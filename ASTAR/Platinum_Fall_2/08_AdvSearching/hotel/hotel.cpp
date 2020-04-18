#include <bits/stdc++.h>
using namespace std;

#define INF INT_MAX
#define MAXN 200000
#define endl '\n'

struct Node {
	int v;
	int c; // longest consecutive
	int p; // longest prefix
	int s; // longest suffix
};

int n, m;
Node segTree[MAXN];
int lazy[MAXN];
int lazyNode[MAXN];

/*void updateVal(int ci, int cl, int cr, int l, int r, int val) {
	if (lazy[ci] != 0) {
		segTree[ci].v += (cr - cl + 1) * lazy[ci];
		if (cl != cr) {
			lazy[2 * ci + 1] = lazy[ci];
			lazy[2 * ci + 2] = lazy[ci];
		}
		lazy[ci] = 0;
	}
	if (cl > r || cr < l || cl > cr) return;
	if (cl >= l && cr <= r) {
		segTree[ci].v += (cr - cl + 1) * val;
		if (cl != cr) {
			lazy[2 * ci + 1] = val;
			lazy[2 * ci + 2] = val;
		}
		return;
	}
	int mid = (cl + cr) / 2;
	updateVal(2 * ci + 1, cl, mid, l, r, val);
	updateVal(2 * ci + 2, mid + 1, cr, l, r, val);
	segTree[ci].v = segTree[2 * ci + 1].v + segTree[2 * ci + 2].v;
}*/

void updateNode(int ci, int cl, int cr, int l, int r, int val) {
	if (lazyNode[ci] != -1) {
		segTree[ci].c = lazyNode[ci] * (cr - cl + 1);
		segTree[ci].p = lazyNode[ci] * (cr - cl + 1);
		segTree[ci].s = lazyNode[ci] * (cr - cl + 1);
		if (cl != cr) {
			lazyNode[2 * ci + 1] = lazyNode[ci];
			lazyNode[2 * ci + 2] = lazyNode[ci];
		}
		lazyNode[ci] = -1;
	}
	if (cl > r || cr < l || cl > cr) return;
	if (cl >= l && cr <= r) {
		segTree[ci].c = val * (cr - cl + 1);
		segTree[ci].p = val * (cr - cl + 1);
		segTree[ci].s = val * (cr - cl + 1);
		if (cl != cr) {
			lazyNode[2 * ci + 1] = val;
			lazyNode[2 * ci + 2] = val;
		}
		return;
	}
	int mid = (cl + cr) / 2;
	updateNode(2 * ci + 1, cl, mid, l, r, val);
	updateNode(2 * ci + 2, mid + 1, cr, l, r, val);
	segTree[ci].c = max(max(segTree[2 * ci + 1].c, segTree[2 * ci + 2].c), segTree[2 * ci + 1].s + segTree[2 * ci + 2].p);
	segTree[ci].p = (mid - cl + 1 == segTree[2 * ci + 1].p ? segTree[2 * ci + 1].p + segTree[2 * ci + 2].p : segTree[2 * ci + 1].p);
	segTree[ci].s = (cr - (mid + 1) + 1 == segTree[2 * ci + 2].s ? segTree[2 * ci + 1].s + segTree[2 * ci + 2].s : segTree[2 * ci + 2].s);
}

void update(int l, int r, int val) {
	// updateVal(0, 0, n - 1, l, r, val);
	updateNode(0, 0, n - 1, l, r, val);
}

void updateLazy(int index, int l, int r) {
	if (lazyNode[index] != -1) {
		segTree[index].c = lazyNode[index] * (r - l + 1);
		segTree[index].p = lazyNode[index] * (r - l + 1);
		segTree[index].s = lazyNode[index] * (r - l + 1);
		if (l != r) {
			lazyNode[2 * index + 1] = lazyNode[index];
			lazyNode[2 * index + 2] = lazyNode[index];
		}
		lazyNode[index] = -1;
	}
}

pair<int, int> query(int index, int l, int r, int length) {
	/*if (lazy[index] != 0) {
		segTree[index].v += (r - l + 1) * lazy[index];
		if (l != r) {
			lazy[2 * index + 1] = lazy[index];
			lazy[2 * index + 2] = lazy[index];
		}
		lazy[index] = 0;
	}*/
	updateLazy(index, l, r);
	updateLazy(index * 2 + 1, l, (r + l) / 2);
	updateLazy(index * 2 + 2, (r + l) / 2 + 1, r);
	int mid = (l + r) / 2;
	if (segTree[2 * index + 1].c >= length) {
		return query(2 * index + 1, l, mid, length);
	}
	else if (segTree[2 * index + 1].s + segTree[2 * index + 2].p >= length) {
		return make_pair(mid + 1 - segTree[2 * index + 1].s, length);
	}
	else if (segTree[2 * index + 2].c >= length) {
		return query(2 * index + 2, mid + 1, r, length);
	}
	return make_pair(-1, -1);
}

int main() {
//	freopen("input.txt", "r", stdin);
	fill(lazyNode, lazyNode + MAXN, -1);
	cin >> n >> m;
	int q;
	update(0, n - 1, 1);
	// cout << segTree[0].c << " " << segTree[0].p << " " << segTree[0].s << endl;
	for (int i = 0; i < m; ++i) {
		cin >> q;
		if (q == 1) {
			int l;
			cin >> l;
			pair<int, int> qu = query(0, 0, n - 1, l);
			if (qu.second == -1) {
				cout << 0 << endl;
			}
			else {
				update(qu.first, qu.first + qu.second - 1, 0);
				cout << qu.first + 1 << endl;
			}
		}
		else {
			int a, b;
			cin >> a >> b;
			--a;
			update(a, a + b - 1, 1);
		}
	}
	/*for (int i = 0; i < 15; ++i) {
		cout << i << " " << segTree[i].c << " " << segTree[i].p << " " << segTree[i].s << endl;
	}*/
}