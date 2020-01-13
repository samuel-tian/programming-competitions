#include <bits/stdc++.h>

using namespace std;

#define INF INT_MAX
#define endl '\n'
#define MAXT 10000
#define MAXS 100
#define MAXN 10000

int t, s, n;
vector<pair<pair<int, int>, int> > lessons; // starting, duration, skill
vector<pair<int, int> > slopes; // skill, time
int skillSlope[MAXS + 1]; // slope with the shortest duration given skill s
int dp[MAXT + 1][MAXS + 1];

int main() {
    cin >> t >> s >> n;
    lessons.resize(s);
    slopes.resize(n);
    for (int i = 0; i < s; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        lessons[i] = make_pair(make_pair(a - 1, b), c);
    }
    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        slopes[i] = make_pair(a, b);
    }
    int iter = 0;
    sort(slopes.begin(), slopes.end());
    skillSlope[0] = INF;
    for (int i = 1; i < MAXS; ++i) {
        int minTime = skillSlope[i - 1];
        while (slopes[iter].first <= i && iter < n) {
            minTime = min(minTime, slopes[iter].second);
//            cout << "pass" << endl;
            ++iter;
        }
        skillSlope[i] = minTime;
    }
    slopes.clear();
    sort(lessons.begin(), lessons.end());
    iter = 0;
    for (int i = 0; i <= t; ++i) {
        for (int j = 1; j <= MAXS; ++j) {
            dp[i][j] = -1;
        }
    }
//    cerr << "pass" << endl;
    dp[0][1] = 0;
    for (int i = 0; i < t; ++i) {
        for (int j = 1; j <= MAXS; ++j) {
            if (dp[i][j] == -1) continue;
            while (lessons[iter].first.first == i && iter < s) {
                if (i + lessons[iter].first.second <= t) {
                    dp[i + lessons[iter].first.second][lessons[iter].second] = max(dp[i][j], dp[i + lessons[iter].first.second][lessons[iter].second]);
                }
                ++iter;
            }
            if (skillSlope[j] != INF) {
                if (i + skillSlope[j] <= t) {
                    dp[i + skillSlope[j]][j] = max(dp[i][j] + 1, dp[i + skillSlope[j]][j]);
                }
            }
            dp[i + 1][j] = max(dp[i][j], dp[i + 1][j]);
        }
    }
    int ret = -1;
    for (int j = 1; j < MAXS; ++j) {
        ret = max(ret, dp[t][j]);
//        cout << dp[t][j] << " ";
    }
//    cout << endl;
    cout << ret << endl;
}
