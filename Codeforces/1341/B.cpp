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

struct max_queue {
	int sz = 0;
	deque<pi> q;
	max_queue(int sz) {
		this->sz = sz;
	}
	void insert(pi a) {
		while (!q.empty() && q.back().f <= a.f) {
			q.pop_back();
		}
		q.push_back(a);
	}
	int query(int i) {
		while (q.front().s < i - sz + 1) {
			q.pop_front();
		}
		return q.front().f;
	}
};

int main() {
	chrono::high_resolution_clock::time_point t0 = chrono::high_resolution_clock::now();

	setIO();
	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		int a[n];
		FOR (i, 0, n) cin >> a[i];
		int peak[n];
		FOR (i, 0, n) {
			peak[i] = 0;
			if (i == 0 || i == n-1) continue;
			if (a[i] > a[i-1] && a[i] > a[i+1]) peak[i] = 1;
		}
		FOR (i, 1, n) {
			peak[i] += peak[i-1];
		}
//		PRSP(peak, n);
		int ret = 0, l = 0;
		FOR (i, 0, n) {
			if (i + k - 2 >= n) break;
			if (peak[i+k-2] - peak[i] > ret) {
				ret = peak[i+k-2] - peak[i];
				l = i;
			}
		}
		cout << ret+1 << " " << l+1 << endl;
	}

	chrono::high_resolution_clock::time_point t1 = chrono::high_resolution_clock::now();
//	cout << "TIME: " << chrono::duration_cast<chrono::milliseconds>(t1 - t0).count() << " ms" << endl;
}
