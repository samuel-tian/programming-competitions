#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
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
#define PRSP(x, a) for (int rv = 0; rv < a; ++rv) {cout << ((rv==0 ? "" : " ")) << x[rv];} cout << endl;
#define mppi(a, b, c) mp(mp((a), (b)), (c))
#define mpip(a, b, c) mp((a), mp((b), (c)))
#define max3(a, b, c) max(max((a), (b)), (c));

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

const int INF = INT_MAX;
const int NINF = INT_MIN;
const int MAXLOG = 21;
const int MAXSEG = (1<<18);
const int MUL = 1000001;
const int MOD = 1000000007;

int main() {
	setIO("stdio");
	int t;
	cin >> t;
	FOR (iteration, 0, t) {
		int n, m;
		cin >> n >> m;
		if ((n*m)%2==1) {
			FOR (i, 0, n) {
				FOR (j, 0, m) {
					if (i % 2 == 0) {
						cout << ((j % 2 == 0) ? "B" : "W");
					}
					else {
						cout << ((j % 2 == 0) ? "W" : "B");
					}
				}
				cout << endl;
			}
		}
		else {
			cout << "B";
			FOR (j, 0, m-1) {
				cout << ((j % 2 == 0) ? "B" : "W");
			}
			cout << endl;
			FOR (i, 0, n-1) {
				FOR (j, 0, m) {
					if (i % 2 == 0) {
						cout << ((j % 2 == 0) ? "B" : "W");
					}
					else {
						cout << ((j % 2 == 0) ? "W" : "B");
					}
				}
				cout << endl;
			}
		}
	}
}
