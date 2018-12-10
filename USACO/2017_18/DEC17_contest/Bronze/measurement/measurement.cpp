/*input
4
7 Mildred +3
4 Elsie -1
9 Mildred -1
1 Bessie +2
*/
#include <iostream>
#include <algorithm>
#include <utility>

using namespace std;

#define endl '\n'
#define MAXN 100

pair<int, pair<int, int> > events[MAXN];
int galsProduced[3] = {7, 7, 7};

int getLargest() {
	if (galsProduced[0] > galsProduced[1] && galsProduced[0] > galsProduced[2]) return 1;
	else if (galsProduced[1] > galsProduced[0] && galsProduced[1] > galsProduced[2]) return 2;
	else if (galsProduced[2] > galsProduced[0] && galsProduced[2] > galsProduced[1]) return 3;
	else if (galsProduced[0] > galsProduced[1] && galsProduced[0] == galsProduced[2]) return 13;
	else if (galsProduced[0] > galsProduced[2] && galsProduced[0] == galsProduced[1]) return 12;
	else if (galsProduced[1] > galsProduced[0] && galsProduced[1] == galsProduced[2]) return 23;
	else return 123;
}

int main() {
	freopen("measurement.in", "r", stdin);
	freopen("measurement.out", "w", stdout);
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> events[i].first;
		string temp;
		cin >> temp;
		if (temp == "Bessie") events[i].second.first = 0;
		else if (temp == "Elsie") events[i].second.first = 1;
		else events[i].second.first = 2;
		cin >> events[i].second.second;
	}
	sort(events, events + n);

	int counter = 0;
	int largest = -1;
	for (int i = 0; i < n; ++i) {
		//cout << events[i].first << " " << events[i].second.first << " " << events[i].second.second << endl;
		galsProduced[events[i].second.first] += events[i].second.second;
		if (getLargest() != largest) {
			largest = getLargest();
			++counter;
		}
	}

	cout << counter << endl;

	fclose(stdin);
	fclose(stdout);
}