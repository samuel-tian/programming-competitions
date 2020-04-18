#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pi;
typedef pair<pair<int, int>, int> ppi;
typedef pair<int, pair<int, int> > pip;
typedef vector<int> vi;
typedef vector<pair<int, int> > vpi;

#define f first
#define s second
#define pb push_back
#define mp make_pair
#define endl '\n'

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FORd(i, a, b) for (int i = (b)-1; i >= (a); --i)
#define PRSP(i, a, x) for (int i = 0; i < (a); ++i) {cout << x[i] << " ";} cout << endl;
#define mppi(a, b, c) mp(mp((a), (b)), (c))
#define mpip(a, b, c) mp((a), mp((b), (c)))

const int MAXN = 100005;
const int INF = INT_MAX;
const int MAXLOG = 21;
const int MAXSEG = (1<<18);

void setIO(string name) {
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (name == "input") {
        freopen("input.txt","r",stdin);
    }
    else if (name == "stdio") {

    }
    else {
        freopen((name+".in").c_str(),"r",stdin);
        freopen((name+".out").c_str(),"w",stdout);
    }
}

int n, d;
vector<pair<double, int> > intersections;
int first[MAXN];
int fenwick[2 * MAXN];

void insert(int index, int val) {
    ++index;
    while (index <= 2*n) {
        fenwick[index] += val;
        index += index & (-index);
    }
}

int get(int index) {
    int ret = 0;
    ++index;
    while (index > 0) {
        ret += fenwick[index];
        index -= index & (-index);
    }
    return ret;
}

int psum(int l, int r) { // exclusive
    return get(r) - get(l - 1);
}

void computeIntersections(double a, double b, double c, int i) {
    if (abs(c / (d * sqrt(a * a + b * b)) > 1)) return;
    double angle = acos(-1 * c / (d * sqrt(a * a + b * b)));
    intersections.pb(mp(atan2(b, a) + angle, i));
    intersections.pb(mp(atan2(b, a) - angle, i));
}

int main() {
    setIO("stdio");
    cin >> n >> d;
    FOR (i, 0, n) {
        double a, b, c;
        cin >> a >> b >> c;
        computeIntersections(a, b, c, i);
    }
    FOR (i, 0, intersections.size()) {
        if (intersections[i].first < 0) {
            intersections[i].first = intersections[i].first + 2 * M_PI;
        }
    }
    sort(intersections.begin(), intersections.end());
    fill(first, first + n, -1);
    int ret = 0;
    FOR (i, 0, intersections.size()) {
        int ind = intersections[i].second;
//        cout << intersections[i].second << " " << intersections[i].first * 180 / M_PI << endl;
        if (first[ind] == -1) {
            first[ind] = i;
            insert(i, 1);
        }
        else {
            insert(i, 0);
            insert(first[ind], -1);
            ret += psum(first[ind], i);
//            cout << first[ind] << " " << psum(first[ind], i) << endl;
        }
        /*FOR (i, 0, 2*n) {
            cout << psum(i, i) << " ";
        } cout << endl;*/
    }
    cout << ret << endl;
}