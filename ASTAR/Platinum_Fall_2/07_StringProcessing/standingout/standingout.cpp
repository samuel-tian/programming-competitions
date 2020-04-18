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
#define max3(a, b, c) max(max((a), (b)), (c));

const int MAXN = 200005;
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

struct suffix {
	int id;
	pi rank;
	bool operator < (suffix &other) {
		return rank < other.rank;
	}
};

int n;
string str, s[MAXN];
suffix r[MAXN]; // ranks
int suf[MAXN]; // suffix array
int lcp[MAXN];

int segTree[MAXSEG];

int query(int node, int a, int b, int i, int j) {
	if (a >= i && b <= j) {
		return segTree[node];
	}
	if (a > j || b < i) {
		return INF;
	}
	int mid = (a + b) / 2;
	int l = query(2 * node + 1, a, mid, i, j);
	int r = query(2 * node + 2, mid + 1, b, i, j);
	return min(l, r);
}

void update(int node, int a, int b, int i, int value) {
	if (i < a || i > b) {
		return;
	}
	if (a != b) {
		int mid = (a + b) / 2;
		update(2 * node + 1, a, mid, i, value);
		update(2 * node + 2, mid + 1, b, i, value);
		segTree[node] = min(segTree[2 * node + 1], segTree[2 * node + 2]);
	}
	else {
		segTree[node] = value;
	}
}

void generate_suf(string s) {
	int t = s.size();
	FOR (i, 0, t) {
		r[i] = {i, mp(s[i] - 'a', (i == t-1) ? -1 : s[i+1]-'a')};
	}
	sort(r, r + t);
	int ind[t];
	for (int k = 4; k < 2 * t; k = k * 2) {
		int rank = 0;
		int prev_rank = r[0].rank.f;
		r[0].rank.f = rank;
		ind[r[0].id] = 0;
		FOR (i, 1, t) {
			if (r[i].rank.f == prev_rank && r[i].rank.s == r[i-1].rank.s) {
				prev_rank = r[i].rank.f;
				r[i].rank.f = rank;
			}
			else {
				prev_rank = r[i].rank.f;
				r[i].rank.f = ++rank;
			}
			ind[r[i].id] = i;
		}
		FOR (i, 0, t) {
			int next_index = r[i].id + k/2;
			if (next_index >= t) r[i].rank.s = -1;
			else r[i].rank.s = r[ind[next_index]].rank.f;
		}
		sort(r, r + t);
	}
	FOR (i, 0, t) {
		suf[i] = r[i].id;
	}
}

void generate_lcp(string s) {
	int t = s.size();
	int inv[t];
	FOR (i, 0, t) {
		inv[suf[i]] = i;
	}
	int k = 0;
	FOR (i, 0, t) {
		if (inv[i] == t-1) {
			k = 0;
			continue;
		}
		int j = suf[inv[i] + 1];
		while (i + k < t && j + k < t && s[i + k] == s[j + k]) k++;
		lcp[inv[i]] = k;
		if (k > 0) k--;
	}
	fill(segTree, segTree + MAXLOG, INF);
	FOR (i, 0, t) {
		update(0, 0, t-1, i, lcp[i]);
	}
	/*FOR (i, 0, t) {
		cout << query(0, 0, t-1, i, i) << " ";
	} cout << endl;
	PRSP(i, t, lcp);*/
}

int main() {
	setIO("stdio");
	cin >> n;
	int strid[MAXN];
	int charid[MAXN];
	int iter = 0;
	FOR (i, 0, n) {
		cin >> s[i];
		str += s[i];
		FOR (j, 0, s[i].size()) {
			charid[iter] = j;
			strid[iter++] = i;
		}
		str += '?';
		strid[iter++] = -1;
	}
	generate_suf(str);
	generate_lcp(str);
	int ans[n];
	fill(ans, ans + n, 0);
	FOR (i, 0, str.size()) {
		if (strid[suf[i]] == -1) continue;
		int l = i;
		int r = i;
		while (l>=0 && (strid[suf[l]] == strid[suf[i]] || strid[suf[l]] == -1)) --l;
		while (r<str.size() && (strid[suf[r]] == -1 || strid[suf[r]] == strid[suf[i]])) ++r;
		int lp = 0, rp = 0;
		if (l != -1) {
			lp = query(0, 0, str.size()-1, l, i-1);
		}
		if (strid[suf[r]] != strid[suf[i]]) {
			rp = query(0, 0, str.size()-1, i, r-1);
		}
		int ret = s[strid[suf[i]]].size() - charid[suf[i]] - max3(lp, rp, lcp[i]);
//		cout << l << " " << r << endl;
		if (ret < 0) continue;
		ans[strid[suf[i]]] += ret;
	}
	/*FOR (i, 0, str.size()) {
		cout << strid[suf[i]] << " " << str.substr(suf[i]) << " " << lcp[i] << " " << lptemp[i] << " " << rptemp[i] << " " << temp[i] << endl;
	}*/
	for (int i : ans) {
		cout << i << endl;
	}
}