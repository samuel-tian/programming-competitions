#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define endl '\n'
#define INF (int)((1<<31)-1)
#define MAXN 100000

int n, pipe1, pipe2, totalPipes;
int pipesTo[MAXN], pipesFrom[MAXN], pipeCount[MAXN];
vector<int> nextPipe[MAXN], start;
bool visited[MAXN];
queue<int> q;

int main() {
	freopen("chocmilk_cases\\chocmilk.1.in", "r", stdin);
	cin >> n;
	for (int i = 0; i < n-1; i++) {
		cin >> pipe1 >> pipe2;
		pipe1--; pipe2;
		nextPipe[pipe1].push_back[pipe2];
		pipesTo[pipe2]++; pipesFrom[pipe1]++;
	}

	for (int i = 0; i < n; i++) {
		pipeCount[i] = 0;
		if (pipesTo[i] == 0) {
			q.push(i);
			start.push_back(i);
			pipeCount[i]++;
			totalPipes++;
		}
	}

	int firstJoint;
	while (true) {
		int current = q.front();
		q.pop();
		if (pipeCount[current] == totalPipes && start.find(i) == start.end()) {
			firstJoint = current;
			break;
		}
		for (int i = 0; i < nextPipe[current].size(); i++) {
			int nextJoint = nextPipe[current][i];
			pipeCount[nextJoint] += pipeCount[current];
			if (!visited[nextJoint]) {
				q.push(nextJoint);
				visited[nextJoint] = true;
			}
			//cout << current << " " << nextPipe << endl;
		}
	}
	cout << firstJoint << endl;

	fclose(stdin);
	return 0;
}
