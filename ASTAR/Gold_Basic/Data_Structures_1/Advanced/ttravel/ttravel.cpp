#include <bits/stdc++.h>
#define f first
#define s second
#define pb push_back
#define ll long long
#define mp make_pair
#define endl '\n'
#define sp << ' ' <<
using namespace std;
typedef pair<int, int> pii;
typedef vector<pii> vii;
const int INF = 2000000000;
const int MAXN = 80000;

int main() {

	// f is previous
	// s is current
	pii queryTime[MAXN+1];
	queryTime[0].f = -1;
	queryTime[0].s = -1;
	freopen("/mnt/c/Users/Samuel/Documents/Programs/USACO/ASTAR/Gold_Basic/Data_Structures_1/Challenge_Problems/ttravel/ttravel_cases/ttravel.1.in", "r", stdin);
	int n; cin >> n;
	char c; int m;
	for (int i = 1; i <= n; i++) {
		cin >> c;
		if (c == 's') {
			queryTime[i].f = queryTime[queryTime[i-1].f].f;
			queryTime[i].s = queryTime[queryTime[i-1].f].s;
		}
		else if (c == 'a') {
			cin >> m;
			queryTime[i].f = i-1;
			queryTime[i].s = m;
		}
		else {
			cin >> m;
			queryTime[i].f = queryTime[m-1].f;
			queryTime[i].s = queryTime[m-1].s;
		}
		cout << queryTime[i].s << endl;
	}

	fclose(stdin);
	return 0;
}
