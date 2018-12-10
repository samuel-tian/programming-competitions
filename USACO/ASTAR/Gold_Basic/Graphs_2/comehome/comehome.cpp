#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
const int INF = ((1LL<<31)-1);

struct Pasture {
	int d;
	int other;
};

vector<Pasture> adjacent[52];
int distToFarm[52];
int p;
queue<int> q;

int main() {
	for (int i = 0; i < 52; i++) {
		distToFarm[i] = INF;
	}
	distToFarm[51] = 0;
	cin >> p;
	for (int i = 0; i < p; i++) {
		char pastureA, pastureB; int dist;
		int intPastureA, intPastureB;
		cin >> pastureA >> pastureB >> dist;
		if (pastureA >= 65 && pastureA <= 90) {
			intPastureA = pastureA - 'A' + 26;
		}
		else {
			intPastureA = pastureA - 'a';
		}
		if (pastureB >= 65 && pastureB <= 90) {
			intPastureB = pastureB - 'A' + 26;
		}
		else {
			intPastureB = pastureB - 'a';
		}
		adjacent[intPastureA].push_back(Pasture{dist, intPastureB});
		adjacent[intPastureB].push_back(Pasture{dist, intPastureA});
	}
	q.push(51);
	while (!q.empty()) {
		int current = q.front();
		q.pop();
		for (int i = 0; i < adjacent[current].size(); i++) {
			Pasture next = adjacent[current][i];
			if (distToFarm[current] + next.d < distToFarm[next.other]) {
				distToFarm[next.other] = distToFarm[current] + next.d;
				q.push(next.other);
			}
		}
	}
	int minDist = INF;
	char minChar = ' ';
	for (int i = 26; i < 51; i++) {
		if (distToFarm[i] < minDist) {
			minDist = distToFarm[i];
			minChar = 'A' + i - 26;
		}
	}
	cout << minChar << " " << minDist << endl;
}
