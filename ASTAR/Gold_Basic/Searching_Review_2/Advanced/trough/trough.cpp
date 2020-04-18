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
const int MAXN = 20;
const int MAXM = 100;

int main() {
	int n, m;
	string temp;
	pii questions[MAXM];
	int ans = -1;
	freopen("trough_cases\\trough.10.out", "r", stdin); getline(cin, temp); cout << temp << endl; fclose(stdin);
	freopen("trough_cases\\trough.10.in", "r", stdin);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> questions[i].f >> questions[i].s;
		int sum = 0;
		for (int j = 0; j < n; j++){
			sum += pow(2, j) * ( (int) (questions[i].f / pow(10, j)) % 10);
		}
		questions[i].f = sum;
	}
	for (int x = 0; x < 1<<n; x++) {
		bool possible = true;
		for (int i = 0; i < m; i++) {
			int counter = 0;
			for (int j = 0; j < n; j++)
				if ((1<<j & questions[i].f) > 0 && (1<<j & x) > 0)
					counter++;
			if (counter != questions[i].s){
				possible = false;
				break;
			}
		}
		if (possible && ans == -1) {
			ans = x;
		}
		else if (possible && ans != -1) {
			ans = -2;
			cout << "NOT UNIQUE" << endl;
			break;
		}
	}
	if (ans >= 0) {
		for (int i = n-1; i >= 0; i--) {
			if ( (1<<i & ans) > 0) cout << '1';
			else cout << '0';
		}
		cout << endl;
	}
	else if (ans == -1)
		cout << "IMPOSSIBLE" << endl;
	cout << "testing" sp ans << endl;
	fclose(stdin);
	return 0;
}
