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
const int MAXN = 1000000;

int heights[MAXN + 1];
int lookup[MAXN];
int main() {
	int n;
	/*freopen("/mnt/c/Users/Samuel/Documents/Programs/USACO/ASTAR/Gold_Basic/Data_Structures_1/Challenge_Problems/lookup/lookup_cases/lookup.1.out", "r", stdin);
	string temp;
	while (getline(cin, temp)) {
		cout << temp << " ";
	}
	cout << endl;
	fclose(stdin);*/

	//freopen("/mnt/c/Users/Samuel/Documents/Programs/USACO/ASTAR/Gold_Basic/Data_Structures_1/Challenge_Problems/lookup/lookup_cases/lookup.1.in", "r", stdin);
	cin >> n;
	heights[n] = INF;
	for (int i = 0; i < n; i++) {
		cin >> heights[i];
	}
	stack<int> q;
	q.push(n);
	for (int i = n - 1; i >= 0; i--) {
		while (heights[i] >= heights[q.top()]) {
			q.pop();
		}
		lookup[i] = q.top();
		q.push(i);
	}
	for (int i = 0; i < n; i++){
		if (lookup[i] == n) cout << 0 << endl;
		else cout << lookup[i] + 1 << endl;
	}
	//fclose(stdin);
	return 0;
}
