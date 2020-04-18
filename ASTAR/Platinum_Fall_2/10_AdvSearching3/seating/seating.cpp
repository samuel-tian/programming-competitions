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

const int MAXN = 500000;
const int INF = INT_MAX;
const int MAXLOG = 21;
const int MAXSEG = (1<<20);

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

ppi operator+(const ppi &l, const ppi &r) {
	return mp(mp(l.f.f+r.f.f, l.f.s+r.f.s), l.s+r.s);
}

int n, m;
ppi segTree[MAXSEG]; // longest substring, longest prefix, longest suffix
int lazy[MAXSEG];

void updateRange(int node, int l, int r, ppi val) {
	segTree[node].f.f = (r - l + 1) * val.f.f;
	segTree[node].f.s = (r - l + 1) * val.f.s;
	segTree[node].s = (r - l + 1) * val.s;
}

void updateLazy(int node, int l, int r) {
	if (lazy[node] != -1) {
		updateRange(node, l, r, mppi(lazy[node], lazy[node], lazy[node]));
		if (l != r) {
			lazy[2 * node + 1] = lazy[node];
			lazy[2 * node + 2] = lazy[node];
		}
		lazy[node] = -1;
	}
}

void update(int node, int a, int b, int i, int j, int val) {
	updateLazy(node, a, b);
	if (a > b || a > j || b < i) return;
	if (a >= i && b <= j) {
		updateRange(node, a, b, mppi(val, val, val));
		if (a != b) {
			lazy[2 * node + 1] = val;
			lazy[2 * node + 2] = val;
		}
		return;
	}
	int mid = (a + b) / 2;
	update(node * 2 + 1, a, mid, i, j, val);
	update(node * 2 + 2, mid + 1, b, i, j, val);
	int l = 2 * node + 1;
	int r = 2 * node + 2;
	segTree[node].f.f = max(max(segTree[l].f.f, segTree[r].f.f), segTree[l].s + segTree[r].f.s);
	segTree[node].f.s = (mid - a + 1 == segTree[l].f.s) ? segTree[l].f.s + segTree[r].f.s : segTree[l].f.s;
	segTree[node].s = (b - mid == segTree[r].s) ? segTree[r].s + segTree[l].s : segTree[r].s;
}

int query(int node, int l, int r, int length) {
	int mid = (l + r) / 2;
	updateLazy(node, l, r);
	updateLazy(2 * node + 1, l, mid);
	updateLazy(2 * node + 2, mid + 1, r);
	if (segTree[2 * node + 1].f.f >= length) {
		return query(2 * node + 1, l, mid, length);
	}
	else if (segTree[2 * node + 1].s + segTree[2 * node + 2].f.s >= length) {
		return mid + 1 - segTree[2 * node + 1].s;
	}
	else if (segTree[2 * node + 2].f.f >= length) {
		return query(2 * node + 2, mid + 1, r, length);
	}
	return -1;
}

int main() {
	setIO("stdio");
	cin >> n >> m;
	fill(lazy, lazy + sizeof(lazy) / sizeof(int), -1);
	char c; int a, b;
	int counter = 0;
	update(0, 0, n-1, 0, n-1, 1);
	FOR (i, 0, m) {
		cin >> c;
		if (c == 'A') {
			cin >> a;
			int q = query(0, 0, n-1, a);
			if (q == -1) ++counter;
			else update(0, 0, n-1, q, q+a-1, 0);
		}
		if (c == 'L') {
			cin >> a >> b;
			update(0, 0, n-1, a-1, b-1, 1);
		}
	}
	cout << counter << endl;
}