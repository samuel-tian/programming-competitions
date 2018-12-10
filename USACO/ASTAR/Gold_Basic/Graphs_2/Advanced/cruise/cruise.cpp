#include <iostream>
#include <utility>
#include <set>

using namespace std;

#define endl '\n'
#define INF (int)((1LL<<31) - 1)
#define MAXN 1000
#define MAXM 500
typedef pair<int, int> Port;

int n, m, k;
Port ports[MAXN];
int nextPort[MAXN], iterToNext[MAXN];
bool dir[MAXM];
/* 1 is left, 0 is right */
/* first is left, second is right */

int findNextPort(int curPort) {
	for (int i = 0; i < m; ++i) {
		if (dir[i]) curPort = ports[curPort].first;
		else curPort = ports[curPort].second;
	}
	return curPort;
}

/* first is the start of the cycle, second is the length of the loop */
pair<int, int> findCycle() {
	set<int> portIter;
	int current = 0;
	bool cycleFound = false;
	while (true) {
		portIter.insert(current);
		current = nextPort[current];
		for (set<int>::iterator it = portIter.begin(); it != portIter.end(); ++it) {
			++iterToNext[*it];
		}
		set<int>::iterator it = portIter.find(current);
		if (it != portIter.end()) {
			return make_pair(*it, iterToNext[*it]);
		}
	}

}

int main() {
	//freopen("cruise_cases\\9.out", "r", stdin);
	cin >> n; cout << n << endl; fclose(stdin);
	//freopen("cruise_cases\\9.in", "r", stdin);
	cin >> n >> m >> k;
	for (int i = 0; i < n; ++i) {
		cin >> ports[i].first >> ports[i].second;
		ports[i].first--;
		ports[i].second--;
	}
	for (int i = 0; i < m; ++i) {
		char leftOrRight;
		cin >> leftOrRight;
		if (leftOrRight == 'R') dir[i] = false;
		else dir[i] = true;
	}
	for (int i = 0; i < n; ++i) {
		nextPort[i] = findNextPort(i);
		//cout << i << ": " << nextPort[i] << endl;
	}

	int current = 0;
	pair<int, int> cycleInfo = findCycle();
	while (current != cycleInfo.first) {
		current = nextPort[current];
		k--;
	}
	k = k % (cycleInfo.second);
	for (int i = 0; i< k; i++) {
		current = nextPort[current];
	}
	cout << current + 1 << endl;

	//fclose(stdin);
	return 0;
}
