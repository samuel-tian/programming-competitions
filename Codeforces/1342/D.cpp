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

int find(vi &a, vi &lb, int cnt) {
	int lo = 0, hi = a.size() - 1;
	while (lo < hi) {
		int mid = (lo + hi + 1) / 2;
		if (a[mid] > lb[cnt-1]) hi = mid - 1;
		else lo = mid;
	}
	return lo;
}

int main() {
	chrono::high_resolution_clock::time_point t0 = chrono::high_resolution_clock::now();

	setIO();
	int n, k;
	cin >> n >> k;
	vi a(n);
	FOR (i, 0, n) cin >> a[i];
	sort(a.begin(), a.end());
	vi c(k);
	FOR (i, 0, k) cin >> c[i];
	vi lb(n);
	int iter = k;
	FOR (i, 0, n) {
		while (iter > 0 && c[iter-1] < i+1)  iter--;
		lb[i] = iter;
	}
//	PRSP(lb, lb.size());
	vector<vi> ans;
	while (!a.empty()) {
		vi ret;
		int cnt = 1;
		int iter = find(a, lb, cnt);
		while (true) {
			if (a.empty()) break;
			iter = find(a, lb, cnt);
			if (iter == 0 && a[iter] > lb[cnt-1]) break;
			ret.pb(a[iter]);
			a.erase(a.begin() + iter);
//			if (iter != 0) --iter;
			cnt++;
		}
		/*cout << ret.size() << " ";
		PRSP(ret, ret.size());*/
		assert(!ret.empty());
		ans.pb(ret);
	}
	cout << ans.size() << endl;
	TRAV (x, ans) {
		cout << x.size() << " ";
		PRSP(x, x.size());
	}

	chrono::high_resolution_clock::time_point t1 = chrono::high_resolution_clock::now();
//	cout << "TIME: " << chrono::duration_cast<chrono::milliseconds>(t1 - t0).count() << " ms" << endl;
}
