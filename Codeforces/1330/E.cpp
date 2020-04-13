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
	FOR (trial, 0, t) {
		int h, g;
		cin >> h >> g;
		int heap[(1<<h)], final[(1<<h)];
		vpi inv;
		FOR (i, 1, (1<<h)) {
			cin >> heap[i];
			inv.pb(mp(heap[i], i));
		}
		fill(final, final + sizeof(final)/sizeof(int), 0);
		sort(inv.begin(), inv.end());
		bool in_final[(1<<h)];
		fill(in_final, in_final + (1<<h), false);
		FOR (i, 0, inv.size()) {
			int k = inv[i].s;
			while (true) {
				if (k <= 0) break;
				if (k < (1<<g)) {
					if (final[k] == 0) {
						break;
					}
				}
				k = k / 2;
			}
//			if (((2*k < (1<<g)) && (final[2*k] == 0 || final[2*k+1] == 0)) || k == 0) continue;
			if (k <= 0) continue;
			if (k < (1<<(g-1))) {
				if (final[2*k] == 0 || final[2*k+1] == 0) continue;
			}
			final[k] = inv[i].f;
			in_final[inv[i].s] = true;
		}
//		PRSP(final, (1<<g));
		ll ret = 0;
		FOR (i, 1, (1<<g)) {
			ret += final[i];
		}
		cout << ret << endl;
		FORd (i, (1<<h) - 1, 1) {
			if (in_final[i]) continue;
			cout << i << " ";
		}
		cout << endl;
	}
}
