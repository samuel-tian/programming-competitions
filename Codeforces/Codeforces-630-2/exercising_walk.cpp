#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
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
#define FORd(i, a, b) for (int i = (a); i >= (b); --i)
#define PRSP(i, a, x) for (int i = 0; i < (a); ++i) {cout << x[i] << " ";} cout << endl;
#define mppi(a, b, c) mp(mp((a), (b)), (c))
#define mpip(a, b, c) mp((a), mp((b), (c)))
#define max3(a, b, c) max(max((a), (b)), (c));

const int MAXN = 100005;
const int INF = INT_MAX;
const int NINF = INT_MIN;
const int MAXLOG = 21;
const int MAXSEG = (1<<18);
const int MUL = 1000001;
const int MOD = 1000000007;

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

int t;
int a, b, c, d;
int x, y, x1, y11, x2, y2;

int main() {
	setIO("stdio");
	cin >> t;
	FOR (i, 0, t) {
		cin >> a >> b >> c >> d;
		cin >> x >> y >> x1 >> y11 >> x2 >> y2;
		int nx = x + b - a;
		int ny = y + d - c;
		if (nx > x2 || nx < x1 || ny > y2 || ny < y11) {
			cout << "No" << endl;
		}
		else if ((a > 0 || b > 0) && x+1>x2 && x-1 < x1) {
			cout << "No" << endl;
		}
		else if ((c > 0 || d > 0) && y+1>y2 && y-1 < y11) {
			cout << "No" << endl;
		}
		else {
			cout << "Yes" << endl;
		}
	}

}