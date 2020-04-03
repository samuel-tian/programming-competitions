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
#define PRSP(i, a, x) for (int i = 0; i < (a); ++i) {cout << x[i] << " ";} cout << endl;
#define mppi(a, b, c) mp(mp((a), (b)), (c))
#define mpip(a, b, c) mp((a), mp((b), (c)))
#define max3(a, b, c) max(max((a), (b)), (c));

const int MAXN = 100005;
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

int main() {
	setIO("stdio");
	int n;
	cin >> n;
	int copy[n], time[n];
	FOR (i, 0, n) {
		cin >> copy[i];
	}
	FOR (i, 0, n) {
		cin >> time[i];
	}
	vi copyv;
	map<int, vi> timem;
	FOR (i, 0, n) {
		copyv.pb(copy[i]);
		timem[copy[i]].pb(time[i]);
	}
	sort(copyv.begin(), copyv.end());
	FORd (i, n-1, 1) {
		if (copyv[i] == copyv[i-1]) {
			copyv.erase(copyv.begin() + i);
		}
	}
	priority_queue<int> pq;
	int viter = 0, iter = copyv[viter];
	ll sum = 0, ret = 0;
	bool b = false;
	while (true) {
		for (int j : timem[iter]) {
			pq.push(j);
			sum += j;
		}
		if (pq.empty()) {
			while (copyv[viter] < iter) {
				++viter;
				if (viter >= copyv.size()) {
					b = true;
					break;
				}
			}
			if (b) break;
			iter = copyv[viter];
		}
		else {
			sum -= pq.top();
			pq.pop();
			ret += sum;
			++iter;
		}
	}
	cout << ret << endl;
}
