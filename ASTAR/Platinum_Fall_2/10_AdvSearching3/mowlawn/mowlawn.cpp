#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pi;
typedef pair<pair<int, int>, int> ppi;
typedef pair<int, pair<int, int> > pip;
typedef vector<int> vi;
typedef vector<pair<int, int> > vpi;
typedef long long ll;

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

const int MAXN = 100005;
const int INF = INT_MAX;
const int NINF = INT_MIN;
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

int n, k;
int c[MAXN];
ll p[MAXN];
ll dp[MAXN];

ll psum(int a, int b) {
	return p[b + 1] - p[a];
}

ll segTree[MAXSEG];
ll lazy[MAXSEG];

void update(int node, int a, int b, int i, int j, ll value) {
	if (lazy[node] != 0) {
		segTree[node] += lazy[node];
		if (a != b) {
			lazy[2 * node + 1] += lazy[node];
			lazy[2 * node + 2] += lazy[node];
		}
		lazy[node] = 0;
	}
	if (a > b || a > j || b < i) return;
	if (a >= i && b <= j) {
		segTree[node] += value;
		if (a != b) {
			lazy[2 * node + 1] += value;
			lazy[2 * node + 2] += value;
		}
		return;
	}
	int mid = (a + b) / 2;
	update(node * 2 + 1, a, mid, i, j, value);
	update(node * 2 + 2, mid + 1, b, i, j, value);
	segTree[node] = max(segTree[2 * node + 1], segTree[2 * node + 2]);
}

ll query(int node, int a, int b, int i, int j) {
	if (lazy[node] != 0) {
		segTree[node] += lazy[node];
		if (a != b) {
			lazy[2 * node + 1] += lazy[node];
			lazy[2 * node + 2] += lazy[node];
		}
		lazy[node] = 0;
	}
	if (a > b || a > j || b < i) return 0;
	if (a >= i && b <= j) return segTree[node];
	int mid = (a + b) / 2;
	ll left = query(2 * node + 1, a, mid, i, j);
	ll right = query(2 * node + 2, mid + 1, b, i, j);
	return max(left, right);
}

int main() {
	setIO("input");
	cin >> n >> k;
	p[0] = 0;
	FOR (i, 0, n) {
		cin >> c[i];
		p[i+1] = p[i] + c[i];
	}
	FOR (i, 0, n) {
		if (i-k == 0) {
			dp[i] = max(psum(0, i-1), psum(1, i));
		}
		else if (i-k < 0) {
			dp[i] = psum(0, i);
			if (i-2 >= 0) {
				dp[i] = max(dp[i], query(0, 0, n-1, 0, i-2));
			}
		}
		else {
			dp[i] = query(0, 0, n-1, i-k-1, i-2);
		}
		update(0, 0, n-1, i, i, dp[i]);
		if (i-k < 0) {
			if (i-1 >= 0) {
				update(0, 0, n-1, 0, i-1, c[i+1]);
			}
		}
		else {
			update(0, 0, n-1, i-k, i-1, c[i+1]);
		}
		/*FOR (i, 0, n) {
			cout << query(0, 0, n-1, i, i) << " ";
		} cout << endl;*/
	}
	/*FOR (i, 0, n) {
		cout << dp[i] << " ";
	} cout << endl;*/
	cout << dp[n-1] << endl;
}