#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
const int INF = ((1LL<<31)-1);

vector<int> times, dists;
double currentTime = 0.0, currentDist = 0.0;
int currentSpeed = 1, distCount = 0, timeCount = 0;

int main() {
	char timeOrDist;
	int n, event;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> timeOrDist >> event;
		if (timeOrDist == 'T') {
			times.push_back(event);
		}
		else {
			dists.push_back(event);
		}
	}
	sort(times.begin(), times.end());
	sort(dists.begin(), dists.end());

	while (distCount + timeCount < n) {
		bool next;
		if (timeCount == times.size()) {
			next = false;
		}
		else if (distCount == dists.size()) {
			next = true;
		}
		else if (times[timeCount] < currentTime + (dists[distCount] - currentDist) * currentSpeed) {
			next = true;
		}
		else {
			next = false;
		}
		if (next) {
			currentDist += (times[timeCount] - currentTime + 0.0) / currentSpeed;
			currentTime = times[timeCount];
			timeCount++;
		}
		else {
			currentTime += (dists[distCount] - currentDist) * currentSpeed;
			currentDist = dists[distCount];
			distCount++;
		}
		currentSpeed++;
	}
	currentTime += (1000 - currentDist) * currentSpeed;
	cout << (int) (round(currentTime)) << endl;
}
