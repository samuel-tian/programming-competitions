#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define endl '\n'
#define INF (int)((1LL<<31)-1)
#define MAXN 100

int n, m;
vector<int> win[MAXN], lose[MAXN];
int winReach[MAXN][MAXN], loseReach[MAXN][MAXN];

bool bfs(int start) {
	queue<int> q;
	winReach[start][start] = loseReach[start][start] = true;
	q.push(start);
	while (!q.empty()) {
		int current = q.front();
		q.pop();
		for (int i = 0; i < win[current].size(); ++i) {
			int next = win[current][i];
			if (!winReach[start][next]) {
				winReach[start][next] = true;
				q.push(next);
			}
		}
	}
	q.push(start);
	while (!q.empty()) {
		int current = q.front();
		q.pop();
		for (int i = 0; i < lose[current].size(); ++i) {
			int next = lose[current][i];
			if (!loseReach[start][next]) {
				loseReach[start][next] = true;
				q.push(next);
			}
		}
	}
	for (int i = 0; i < n; ++i) {
		if (!(winReach[start][i] || loseReach[start][i])) {
			return false;
		}
	}
	return true;
}

int main() {
	cin >> n >> m;
	int first, second;
	for (int i = 0; i < m; ++i) {
		cin >> first >> second;
		first = first - 1, second = second - 1;
		win[first].push_back(second);
		lose[second].push_back(first);
	}

	/*for (int i = 0; i < n; ++i) {
		cout << i << ":" << endl;
		cout << "\twin: ";
		for (int j = 0; j < win[i].size(); ++j) {
			cout << win[i][j] << " ";
		}
		cout << endl << "\tlose: ";
		for (int j = 0; j < lose[i].size(); ++j) {
			cout << lose[i][j] << " ";
		}
		cout << endl;
	}*/

	int determinePosCounter = 0;
	for (int i = 0; i < n; ++i) {
		if (bfs(i)) {
			++determinePosCounter;
		}
	}
	/*for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cout << (winReach[i][j] || loseReach[i][j]) << " ";
		}
		cout << endl;
	}*/
	cout << determinePosCounter << endl;
}
