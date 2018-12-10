/*input
7
1 6
8 6
14 5
19 2
1 8
18 3
10 6
*/

#include <iostream>
#include <algorithm>
#include <utility>

using namespace std;

#define endl '\n'
#define MAXN 10000

int main() {
	int n;
	int counter = 1;
	pair<int, int> events[MAXN];
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> events[i].first >> events[i].second;
	}
	sort(events, events + n);
	/*
	for (int i = 0; i < n; ++i) printf("%-3d ", events[i].first); cout << endl;
	for (int i = 0; i < n; ++i) printf("%-3d ", events[i].second); cout << endl;
	*/
	int currentEndTime = events[n - 1].first;
	for (int i = n - 2; i >= 0; --i) {
		if (events[i].first + events[i].second <= currentEndTime) {
			currentEndTime = events[i].first;
			++counter;
		}
	}
	cout << counter << endl;
}