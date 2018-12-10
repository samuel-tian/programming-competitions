/*input
8
2 6
3 3
2 8
4 5
7 5
5 5
9 1
5 4
*/
#include <iostream>
#include <climits>
#include <set>
#include <algorithm>
#include <utility>

using namespace std;

#define endl '\n'
#define INF INT_MAX
#define MAXN 50000

int n;
pair<int, int> points[MAXN];
pair<int, int> original[MAXN];

int find(pair<int, int> p) {
	for (int i = 0; i < n; ++i) {
		if (original[i] == p) {
			return i;
		}
	}
	return -1;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> points[i].first >> points[i].second;
		original[i].first = points[i].first;
		original[i].second = points[i].second;
	}
	sort(points, points + n);
	set<pair<int, int> > s;
	/*
	first is y coordinate
	second is x coordinate
	*/
	int mindist = INF;
	int a1, a2;
	int leftmost = 0;
	for (int i = 0; i < n; ++i) {
		/*cout << "dist: " << mindist << "; ";
		for (pair<int, int> p: s) {
			cout << p.first << " " << p.second << " ";
		}
		cout << endl;*/
		pair<int, int> cur = points[i];
		while (cur.first - points[leftmost].first > mindist) {
			s.erase(points[leftmost]);
			++leftmost;
		}
		long long head = (long long) cur.second - (long long) mindist;
		long long tail = (long long) cur.second + (long long) mindist;
		// cout << "HEADTAIL: " << head << " " << tail << endl;
		for (set<pair<int, int> >::iterator it = s.begin(); it != s.end(); ++it) {
			// cout << it->first << " " << it->second << endl;
			if (it->second < head || it->second > tail) continue;
			int dist = (it->first - cur.second) * (it->first - cur.second) + (it->second - cur.first) * (it->second - cur.first);
			if (dist <= mindist) {
				pair<int, int> sec = make_pair(it->second, it->first);
				if (dist < mindist) {
					mindist = dist;
					a1 = find(cur);
					a2 = find(sec);
				}
				else if (dist == mindist) {
					if (find(cur) < a1 || (find(cur) == a1 && find(sec) < a2)) {
						a1 = find(cur);
						a2 = find(sec);
					}
				}
			}
		}
		s.insert(make_pair(cur.second, cur.first));
	}
	// cout << ans1.first << " " << ans1.second << endl;
	// cout << ans2.first << " " << ans2.second << endl;
	++a1; ++a2;
	if (a1 < a2) cout << a1 << " " << a2 << endl;
	else cout << a2 << " " << a1 << endl;
}