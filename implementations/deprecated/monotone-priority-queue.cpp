/*
 * Monotone Priority Queue (MPQ)
 * -----------------------------
 * - an MPQ satisfies the invariant that mpq[i] < mpq[j] for all i < j
 * - used for sliding window min/max queries
 */
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
#define PRSP(i, a, x) for (int i = 0; i < (a); ++i) {cout << x[i] << ((i==a-1) ? "\n" : " ");}
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

int n, m;
int a[MAXN];
int mini[MAXN];

int main() {
	setIO("input");
	cin >> n >> m;
	FOR (i, 0, n) {
		cin >> a[i];
	}
	pi mpq[n];
	int s = 0, e = 0;
	FOR (i, 0, n) {
		while (e > s && mpq[e-1].first >= a[i]) e--;
		mpq[e++] = mp(a[i], i);
		while (mpq[s].second < i - m + 1) s++;
		mini[i] = mpq[s].first;
	}
	PRSP(i, n, mini);
}