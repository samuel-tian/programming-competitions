#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
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

#define FOR(i, a, b) for (int (i) = (a); i < (b); ++i)
#define FORd(i, a, b) for (int (i) = (a); i >= (b); --i)
#define TRAV(i, x) for (auto& (i) : (x))
#define PRSP(x, a) for (int rv = 0; rv < a; ++rv) {cout << ((rv==0 ? "" : " ")) << x[rv];} cout << endl;
#define mppi(a, b, c) mp(mp((a), (b)), (c))
#define mpip(a, b, c) mp((a), mp((b), (c)))
#define max3(a, b, c) max(max((a), (b)), (c))
#define min3(a, b, c) min(min((a), (b)), (c))

void setIO(string name = "") {
	ios_base::sync_with_stdio(0); cin.tie(0);
	if (name == "") return;
	if (name == "input") {freopen("input.txt","r",stdin);}
	else {freopen((name+".in").c_str(),"r",stdin); freopen((name+".out").c_str(),"w",stdout);}
}

const int INF = INT_MAX;
const int NINF = INT_MIN;
const int MAXLOG = 21;
const int MAXSEG = (1<<18);
const int MUL = 1000001;
const int MOD = 1000000007;
const ll RANDOM = chrono::high_resolution_clock::now().time_since_epoch().count();
struct chash { ll operator()(ll x) const { return x ^ RANDOM; } };

int main() {
	chrono::high_resolution_clock::time_point t0 = chrono::high_resolution_clock::now();

	setIO();
	int t;
	cin >> t;
	while (t--) {
		int a, b, q;
		cin >> a >> b >> q;
		int l = a * b / __gcd(a, b);
		vi res(l+1);
		FOR (i, 0, l) {
			res[i+1] = ((i%a)%b == ((i%b)%a)) ? 0 : 1;
		}
		FOR (i, 1, l+1) {
			res[i] += res[i-1];
		}
//		cout << l << endl;
//		PRSP(res, res.size());
		FOR (i, 0, q) {
			ll q1, q2;
			cin >> q1 >> q2;
			ll res1 = q1 % l, div1 = q1 / l;
			ll res2 = q2 % l, div2 = q2 / l;
			ll ans = 0;
			if (div1 == div2) {
				ans = res[res2+1] - res[res1];
			}
			else {
				ans += res[l] - res[res1];
				ans += res[res2+1];
				ans += (div2 - div1 - 1) * res[l];
			}
			cout << ans << " ";
		}
		cout << endl;
	}

	chrono::high_resolution_clock::time_point t1 = chrono::high_resolution_clock::now();
//	cout << "TIME: " << chrono::duration_cast<chrono::milliseconds>(t1 - t0).count() << " ms" << endl;
}
