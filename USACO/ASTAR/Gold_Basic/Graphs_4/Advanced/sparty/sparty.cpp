#include <iostream>
#include <vector>
#include <utility>

using namespace std;

#define endl '\n'
#define INF (int)((1LL<<31)-1)
#define MAXN 1000

int n, m, x;
int walkTimeTo[MAXN], walkTimeFrom[MAXN];
vector<pair<int, int> > adjacentTo[MAXN], adjacentFrom[MAXN];
bool visitedTo[MAXN], visitedFrom[MAXN];

int minFarmTo() {
	int ret, mini = INF;
	for (int i = 0; i < n; ++i) {
		if (!visitedTo[i] && walkTimeTo[i] < mini) {
			mini = walkTimeTo[i];
			ret = i;
		}
	}
	return ret;
}

int minFarmFrom() {
	int ret, mini = INF;
	for (int i = 0; i < n; ++i) {
		if (!visitedFrom[i] && walkTimeFrom[i] < mini) {
			mini = walkTimeFrom[i];
			ret = i;
		}
	}
	return ret;
}

void dijkstraTo(int start) {
	fill(walkTimeTo, walkTimeTo + n, INF);
	walkTimeTo[start] = 0;
	for (int times = 0; times < n-1; ++times) {
		int current;
		if (times == 0) current = start;
		else current = minFarmTo();
		visitedTo[current] = true;
		for (int i = 0; i < adjacentTo[current].size(); ++i) {
			pair<int, int> next = adjacentTo[current][i];
			if (!visitedTo[next.second] && walkTimeTo[current] + next.first < walkTimeTo[next.second]) {
				walkTimeTo[next.second] = walkTimeTo[current] + next.first;
			}
		}
	}
}

void dijkstraFrom(int start) {
	fill(walkTimeFrom, walkTimeFrom + n, INF);
	walkTimeFrom[start] = 0;
	for (int times = 0; times < n-1; ++times) {
		int current;
		if (times == 0) current = start;
		else current = minFarmFrom();
		visitedFrom[current] = true;
		for (int i = 0; i < adjacentFrom[current].size(); ++i) {
			pair<int, int> next = adjacentFrom[current][i];
			if (!visitedFrom[next.second] && walkTimeFrom[current] + next.first < walkTimeFrom[next.second]) {
				walkTimeFrom[next.second] = walkTimeFrom[current] + next.first;
			}
		}
	}
}

int main() {
	cin >> n >> m >> x;
	--x;
	int from, to, wTime;
	for (int i = 0; i < m; ++i) {
		cin >> from >> to >> wTime;
		--from; --to;
		adjacentTo[from].push_back(make_pair(wTime, to));
		adjacentFrom[to].push_back(make_pair(wTime, from));
	}

	dijkstraTo(x);
	dijkstraFrom(x);
	int ret = 0;
	for (int i = 0; i < n; ++i) {
		if (walkTimeTo[i] + walkTimeFrom[i] > ret) {
			ret = walkTimeTo[i] + walkTimeFrom[i];
		}
	}
	cout << ret << endl;
}
