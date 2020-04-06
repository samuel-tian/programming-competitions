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
	int t, n;
	cin >> t;
	FOR (test, 0, t) {
		cin >> n;
		int a[n];
		FOR (i, 0, n) {
			cin >> a[i];
			a[i]--;
		}
		int perm[n];
		fill(perm, perm + n, 0);
		FOR (i, 0, n) {
			perm[a[i]]++;
		}
		int j = 0;
		while (perm[j] == 2) {
			j++;
		}
		vpi ans;
		FOR (checking, 0, 2) {
			bool pass = true;
			bool check[n];
			fill(check, check + n, false);
			FOR (i, 0, j) {
				check[a[i]] = true;
			}
			FOR (i, 0, j) {
				if (!check[i]) {
					pass = false;
				}
			}
			fill(check, check + n, false);
			FORd (i, n-1, j) {
				check[a[i]] = true;
			}
			FOR (i, 0, n-j) {
				if (!check[i]) {
					pass = false;
				}
			}
			if (pass) {
				if (checking == 0)
					ans.pb(mp(j, n-j));
				else {
					if (n-j != j) {
						ans.pb(mp(n-j, j));
					}
				}
			}
			reverse(a, a + n);
		}
		cout << ans.size() << endl;
		FOR (i, 0, ans.size()) {
			cout << ans[i].f << " " << ans[i].s << endl;
		}
	}
}
