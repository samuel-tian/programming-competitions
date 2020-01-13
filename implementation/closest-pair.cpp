/*
 * Closest Pair of Points (Divide and Conquer)
 * -------------------------------------------
 * 1) sort the points by x-coordinate
 * 2) find the closest pair of points in the left half and right half
 * 3) find the closest pair of points that cross the line separating the left and right half
 *      a) create a vector of points that are less than D units away from the dividing line
 *      b) sort the vector by y-coordinate
 *      c) for each point, compare with the next 15 points in the vector
 *              i) geometrically proven that you only need 15 comparisons
 * 4) merge the left and right halves
 * Time Complexity: O(n log n)
 */

#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pi;
typedef pair<pair<int, int>, int> pii;
typedef vector<int> vi;
typedef vector<pair<int, int> > vpi;

#define f first
#define s second
#define pb push_back
#define mp make_pair
#define endl '\n'

const int MAXN = 100005;
const int INF = INT_MAX;
const int MAXLOG = 21;
const int MAXSEG = (1<<18);

void setIO(string name) {
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (name == "input") {
        freopen("input.txt","r",stdin);
    }
    else {
        freopen((name+".in").c_str(),"r",stdin);
        freopen((name+".out").c_str(),"w",stdout);
    }
}

int n;
pii points[MAXN];

int dist(pi a, pi b) {
    return (a.f-b.f) * (a.f-b.f) + (a.s-b.s) * (a.s-b.s);
}

pii closestPair(int a, int b) {
    if (a == b) return mp(mp(a, b), INF);
    int mid = (a + b) / 2;
    pii l = closestPair(a, mid);
    pii r = closestPair(mid + 1, b);
    int d = min(l.s, r.s);
    pi ret;
    if (l.s == r.s) ret = min(l.f, r.f);
    else ret = (l.s == d) ? l.f : r.f;
    vector<pii> m;
    for (int i = a; i <= b; ++i) {
        if (abs(points[i].f.f - points[mid].f.f) <= d) {
            m.pb(mp(mp(points[i].f.s, points[i].f.f), points[i].s));
        }
    }
    sort(m.begin(), m.end());
    for (int i = 0; i < m.size(); ++i) {
        for (int j = i + 1; j < i + 16; ++j) {
            if (j >= m.size()) break;
            if (dist(m[i].f, m[j].f) <= d) {
                int mi = min(m[i].s, m[j].s);
                int ma = max(m[i].s, m[j].s);
                if (d == dist(m[i].f, m[j].f)) {
                    if (mp(mi, ma) < ret) {
                        ret = mp(mi, ma);
                    }
                    continue;
                }
                ret = mp(mi, ma);
                d = dist(m[i].f, m[j].f);
            }
        }
    }
    return mp(ret, d);
}

int main() {
//    setIO("input");
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> points[i].f.f >> points[i].f.s;
        points[i].s = i;
    }
    sort(points, points + n);
    pii cp = closestPair(0, n-1);
    cout << cp.f.f+1 << " " << cp.f.s+1 << endl;
}