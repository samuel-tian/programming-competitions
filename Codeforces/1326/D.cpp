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

const int MAXN = 2000005;
const int INF = INT_MAX;
const int NINF = INT_MIN;
const int MAXLOG = 21;
const int MAXSEG = (1<<18);
const int MUL = 1000001;
const int MOD = 1000000007;

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

int pre[MAXN];

void prefix_function(string s) {
	fill(pre, pre + s.size(), 0);
	int n = s.size();
	FOR (i, 1, n) {
		int j = pre[i-1];
		while (j > 0 && s[i] != s[j]) {
			j = pre[j-1];
		}
		if (s[i] == s[j]) {
			++j;
		}
		pre[i] = j;
	}
}

void solve(string t) {
	if (t.size() == 1) {
		cout << t << endl;
		return;
	}
	int counter = 0;
	while (counter < t.size() / 2 && t[counter] == t[t.size() - 1 - counter]) {
		++counter;
	}
	if (counter > 0) cout << t.substr(0, counter);
	string s = t.substr(counter, t.size() - 2 * counter);
	if (s.size() > 0) {
		string sr = s;
		reverse(sr.begin(), sr.end());
		string tot = s + "?" + sr;
		prefix_function(tot);
		string app = s.substr(0, pre[tot.size() - 1]);
		tot = sr + "?" + s;
		prefix_function(tot);
		if (pre[tot.size() - 1] > app.size()) {
			app = sr.substr(0, pre[tot.size() - 1]);
		}
		cout << app;
	}
	if (counter > 0) cout << t.substr(t.size() - counter, counter);
	cout << endl;
}

int main() {
	setIO("stdio");
	int n;
	cin >> n;
	FOR (i, 0, n) {
		string s;
		cin >> s;
		solve(s);
	}
}
