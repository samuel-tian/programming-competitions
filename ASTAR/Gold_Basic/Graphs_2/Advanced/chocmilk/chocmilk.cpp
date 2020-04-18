#include <iostream>
#include <vector>
#include <queue>

using namespace std;
#define INF (int)((1<<31)-1)
#define MAXN 100000
#define endl '\n'

int n, pipe1, pipe2, pipeCount = 0;
vector<int> pipesFrom[MAXN], pipesTo[MAXN];
int numPipesTo[MAXN];
queue<int> q;
bool visited[MAXN];

int main() {
	freopen("chocmilk_cases\\chocmilk.5.in", "r", stdin);

	cin >> n;
	for (int i = 0; i < n-1; i++) {
		cin >> pipe1 >> pipe2;
		pipe1--; pipe2--;
		pipesFrom[pipe1].push_back(pipe2);
		pipesTo[pipe2].push_back(pipe1);
	}
	for (int i = 0; i < n; i++) {
		numPipesTo[i] = 0;
		if (pipesTo[i].empty()) {
			q.push(i);
			numPipesTo[i] = 1;
			pipeCount++;
		}
	}
	/*for (int i = 0; i < n; i++) {
		cout << i << " from: ";
		for (int j = 0; j < pipesFrom[i].size(); j++) {
			cout << pipesFrom[i][j] << " ";
		}
		cout << endl;
		cout << i << " to: ";
		for (int j = 0; j < pipesTo[i].size(); j++) {
			cout << pipesTo[i][j] << " ";
		}
		cout << endl;
	}
	cout << "pipecount " << pipeCount << endl;*/

	int firstJoint;
	while (!q.empty()) {
		int current = q.front();
		q.pop();
		if (numPipesTo[current] == pipeCount) {
			firstJoint = current;
			break;
		}
		for (int i = 0; i < pipesFrom[current].size(); i++) {
			int next = pipesFrom[current][i];
			numPipesTo[next] += numPipesTo[current];
			if (!visited[next]) {
				q.push(next);
				visited[next] = true;
			}
			//cout << current << " " << next << endl;
		}
	}
	if (!pipesTo[firstJoint].empty()) {
		cout << firstJoint + 1 << endl;
	while (pipesFrom[firstJoint].size() == 1) {
		firstJoint = pipesFrom[firstJoint][0];
		cout << firstJoint + 1 << endl;
	}

	fclose(stdin);
	return 0;
}
