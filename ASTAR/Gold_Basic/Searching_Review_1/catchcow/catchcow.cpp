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
const int MAX = 100000;

int main() {
	int n, k;
	int dist[MAX+1];
	for (int i = 0; i < MAX+1; i++) dist[i] = INF;
	//freopen("catchcow_cases\\catchcow.10.out", "r", stdin); cin >> n; cout << n << endl; fclose(stdin);
	//freopen("catchcow_cases\\catchcow.10.in", "r", stdin);
	cin >> n >> k;
	queue<int> q;
	q.push(n);
	dist[n] = 0;
	while (!q.empty()) {
		int current = q.front();
		q.pop();
		if (current == k) continue;
		if (2 * current < MAX && dist[2 * current] > dist[current] + 1 && current < k) {
			dist[2 * current] = dist[current] + 1;
			q.push(2 * current);
		}
		if (current + 1 < MAX && dist[current + 1] > dist[current] + 1 && current < k) {
			dist[current + 1] = dist[current] + 1;
			q.push(current + 1);
		}
		if (current - 1 >= 0 && dist[current - 1] > dist[current] + 1) {
			dist[current - 1] = dist[current] + 1;
			q.push(current - 1);
		}
	}
	cout << dist[k] << endl;
	//fclose(stdin);
	return 0;
}