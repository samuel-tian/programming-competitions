#include <iostream>
#include <climits>
#include <algorithm>
#include <set>
#include <vector>
#include <iterator>
#include <utility>

using namespace std;

#define endl '\n'
#define INF INT_MAX
#define MAXT 10000
#define MAXS 100
#define MAXN 10000
#define MAXC 100

struct Lesson {
	int start, length, skill;
};

struct Slope {
	int length, skill;
};

int t, s, n;
Lesson lessons[MAXS];
Slope slopes[MAXN];
int optimalSlope[MAXC + 1];
// stores the optimal slope for each skill level
int dp[MAXC + 1][MAXT + 1];

int main() {
//	freopen("input.txt", "r", stdin);
	cin >> t >> s >> n;
	set<pair<int, pair<int, int> > > lessonSet;
	for (int i = 0; i < s; ++i) {
		cin >> lessons[i].start >> lessons[i].length >> lessons[i].skill;
		lessonSet.insert(make_pair(lessons[i].start, make_pair(lessons[i].skill, lessons[i].length)));
	}
	vector<pair<int, int> > slopeSet;
	for (int i = 0; i < n; ++i) {
		cin >> slopes[i].skill >> slopes[i].length;
		slopeSet.push_back(make_pair(slopes[i].skill, slopes[i].length));
	}
	sort(slopeSet.begin(), slopeSet.end());
	optimalSlope[0] = INF;
	for (int i = 1; i <= MAXC; ++i) {
		if (i < slopeSet.begin()->first) optimalSlope[i] = INF;
		else {
			vector<pair<int, int> >::iterator lowerbound = lower_bound(slopeSet.begin(), slopeSet.end(), make_pair(i, 0));
			if (lowerbound->first > i) lowerbound = slopeSet.begin() + (int) (lowerbound - slopeSet.begin()) - 1;
			optimalSlope[i] = min(optimalSlope[i - 1], (lowerbound)->second);
		}
	}
	/*for (int i = 0; i <= 5; ++i) {
		cout << optimalSlope[i] << " ";
	}
	cout << endl;*/
	for (int i = 0; i <= MAXC; ++i) {
		for (int j = 0; j <= t; ++j) {
			dp[i][j] = -1;
		}
	}
	dp[1][0] = 0;
	for (int i = 1; i < MAXC; ++i) {
		for (int j = 0; j <= t; ++j) {
			if (dp[i][j] == -1) continue;
			// take a lesson
			set<pair<int, pair<int, int> > >::iterator hi = lessonSet.upper_bound(make_pair(j, make_pair(INF, INF)));
			for (auto it = lessonSet.lower_bound(make_pair(j, make_pair(i, 0))); it != hi; ++it) {
//				cout << it->first << " " << it->second.first << " " << it->second.second << endl;
				int nextSkill = it->second.first;
				int nextTime = j + it->second.second;
				if (nextTime > t) continue;
				dp[nextSkill][nextTime] = max(dp[nextSkill][nextTime], dp[i][j]);
			}
			// ski a slope
			int nextTime = j + optimalSlope[i];
			if (nextTime > t) continue;
			dp[i][nextTime] = max(dp[i][nextTime], dp[i][j] + 1);
			// do nothing
			if (j + 1 > t) continue;
			dp[i][j + 1] = max(dp[i][j + 1], dp[i][j]);
		}
	}
	int ans = -1;
	/*for (int i = 1; i <= 5; ++i) {
		for (int j = 0; j <= t; ++j) {
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}*/
	for (int i = 1; i <= MAXC; ++i) {
		ans = max(ans, dp[i][t]);
	}
	cout << ans << endl;
}
