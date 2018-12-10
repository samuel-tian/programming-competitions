/*input
4 10
7 3 +3
4 2 -1
9 3 -1
1 1 +2
*/
#include <iostream>
#include <algorithm>
#include <utility>
#include <set>

using namespace std;

#define endl '\n'
#define MAXN 100000
#define INF (int)((1LL<<31)-1)

int n, g;
pair<int, pair<int, int> > events[MAXN];
set<pair<int, int> > gal;

int main() {
	//freopen("measurement.in", "r", stdin);
	//freopen("measurement.out", "w", stdout);
	cin >> n >> g;
	for (int i = 0; i < n; ++i) {
		cin >> events[i].first >> events[i].second.first >> events[i].second.second;
		gal.insert(make_pair(g, events[i].second.first));
	}
	sort(events, events+n);

	int counter = 0;
	string largest = "";
	set<pair<int, int> >::iterator it;
	set<pair<int, int> >::reverse_iterator rit;
	for (int i = 0; i < n; ++i) {
		for (it = gal.begin(); it != gal.end(); ++it) {
			if (it->second == events[i].second.first) {
				gal.erase(it);
				gal.insert(make_pair(it->first+events[i].second.second, it->second));
				break;
			}
		}
		string newLarge = "";
		for (rit = gal.rbegin(); rit != gal.rend(); ++rit) {
			if (rit->first == gal.rbegin()->first) {
				newLarge += to_string(rit->second);
		//cout << rit->first << " " << rit->second << " " << "pass" << endl;
			}
			else break;
		}
		/*for (set<pair<int, int> >::iterator itt = gal.begin(); itt != gal.end(); ++itt) {
			cout << itt->first << ":" << itt->second << ", ";
		}
		cout << endl;*/
		if (newLarge != largest) {
			++counter;
			largest = newLarge;
			//cout << i << " " << "newLarge: " << newLarge << endl;
		}
	}
	cout << counter << endl;

	//fclose(stdin);
	//fclose(stdout);
}