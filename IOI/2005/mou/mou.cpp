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
	else if (name == "check") {freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);}
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

struct sum_seg_lazy {
	int def;
	int n;
	vector<ll> segTree, pre, lazy;
	vi comp;
	sum_seg_lazy() {
		this->n = 0;
		segTree.resize(1); lazy.resize(1); pre.resize(1);
		fill(segTree.begin(), segTree.end(), 0);
		fill(lazy.begin(), lazy.end(), INF);
		fill(pre.begin(), pre.end(), 0);
	}
	sum_seg_lazy(int d, vi& c) {
		def = d;
		this->n = c.size(); this->comp = c;
		int sz = 4*n;
		segTree.resize(sz); lazy.resize(sz); pre.resize(sz);
		fill(segTree.begin(), segTree.end(), 0);
		fill(lazy.begin(), lazy.end(), INF);
		fill(pre.begin(), pre.end(), 0);
	}
	void propagate(int node, int a, int b) {
		if (lazy[node] != INF) {
			segTree[node] = lazy[node] * (comp[b+1] - comp[a]);
			pre[node] = lazy[node] * (comp[b+1] - comp[a]);
			if (a != b) {
				lazy[2 * node + 1] = lazy[node];
				lazy[2 * node + 2] = lazy[node];
			}
			lazy[node] = INF;
		}
	}
	void update(int i, int j, int val) {updateUtil(0, 0, n-1, i, j, val);}
	void updateUtil(int node, int a, int b, int i, int j, int val) {
		propagate(node, a, b);
		if (a > b || a > j || b < i) return;
		if (a >= i && b <= j) {
			segTree[node] = val * (comp[b+1] - comp[a]);
			pre[node] = val * (comp[b+1] - comp[a]);
			if (a != b) {
				lazy[2 * node + 1] = val;
				lazy[2 * node + 2] = val;
			}
			return;
		}
		int mid = (a + b) / 2;
		updateUtil(node * 2 + 1, a, mid, i, j, val);
		updateUtil(node * 2 + 2, mid + 1, b, i, j, val);
		segTree[node] = segTree[2 * node + 1] + segTree[2 * node + 2];
		pre[node] = max(pre[2 * node + 1], segTree[2 * node + 1] + pre[2 * node + 2]);
	}
	ll query(int i, int j) { return queryUtil(0, 0, n-1, i, j); }
	ll queryUtil(int node, int a, int b, int i, int j) {
		propagate(node, a, b);
		if (a > b || a > j || b < i) return 0;
		if (a >= i && b <= j) return segTree[node];
		int mid = (a + b) / 2;
		ll l = queryUtil(2*node+1, a, mid, i, j);
		ll r = queryUtil(2*node+2, mid + 1, b, i, j);
		return l + r;
	}
	ll query2(int i) { return query2Util(0, 0, n-1, i); }
	ll query2Util(int node, int a, int b, int i) {
		propagate(node, a, b);
		if (a > b || i < a || i > b) return 0;
		if (a == b) return pre[node];
		int mid = (a + b) / 2;
		if (i <= mid) return query2Util(2*node+1, a, mid, i);
		else {
			propagate(2*node+1, a, mid);
			return segTree[2*node+1] + query2Util(2*node+2, mid+1, b, i);
		}
	}
	ll ans(ll h) { propagate(0, 0, n-1); return ansUtil(0, 0, n-1, h); }
	ll ansUtil(int node, int a, int b, ll h) {
		if (a == b) {
			ll v = query(a, a) / (comp[a+1]-comp[a]);
//			cout << "V: " << v << endl;
			return min((ll)(comp[a] + ((v<=0) ? (int)1e9 : h / v)), (ll)((a==n-1) ? def : comp[a+1]-1));
		}
		int mid = (a + b) / 2;
		propagate(2*node+1, a, mid);
		if (pre[2*node+1] <= h) {
			propagate(2*node+2, mid+1, b);
			return ansUtil(2*node+2, mid + 1, b, h - segTree[2*node+1]);
		}
		else {
			return ansUtil(2*node+1, a, mid, h);
		}
	}
};

int main() {
	chrono::high_resolution_clock::time_point t0 = chrono::high_resolution_clock::now();
	setIO();
	int N;
	cin >> N;
	vector<pair<char, ppi> > q;
	vi comp;
	while (true) {
		char c;
		cin >> c;
		int a, b, d;
		if (c == 'E') break;
		else if (c == 'Q') {
			cin >> a;
			q.pb(mp(c, mppi(0, 0, a)));
		}
		else if (c == 'I') {
			cin >> a >> b >> d;
			--a; --b;
			q.pb(mp(c, mppi(a, b, d)));
			comp.pb(a); comp.pb(a+1); comp.pb(b); comp.pb(b+1);
		}
	}
	comp.pb(0); comp.pb(N);
	sort(comp.begin(), comp.end());
	FORd (i, comp.size()-1, 1) if (comp[i] == comp[i-1]) comp.erase(comp.begin() + i);
	unordered_map<int, int> inv;
	FOR (i, 0, comp.size()) inv[comp[i]] = i;
//	PRSP(comp, comp.size());
	sum_seg_lazy segtree(N, comp);
//	int counter = 1;
	TRAV (a, q) {
		if (a.f == 'Q') {
//			if (counter == 105) cout << a.f << " " << a.s.s << ": ";
			cout << segtree.ans(a.s.s) << endl;
//			counter++;
		}
		else {
			segtree.update(inv[a.s.f.f], inv[a.s.f.s], a.s.s);
			/*FOR (i, 0, comp.size()) {
				cout << segtree.query(i, i) << " ";
			} cout << endl;
			FOR (i, 0, comp.size()) {
				cout << segtree.query2(i) << " ";
			} cout << endl;*/
		}
	}
	/*FOR (i, 0, comp.size()) {
		cout << segtree.query(i, i) << " ";
	} cout << endl;
	cout << "///////////" << endl;
	FOR (i, 0, 6) {
		cout << segtree.ans(i) << endl;
	}*/
	chrono::high_resolution_clock::time_point t1 = chrono::high_resolution_clock::now();
//	cout << "TIME: " << chrono::duration_cast<chrono::milliseconds>(t1 - t0).count() << " ms" << endl;
}
