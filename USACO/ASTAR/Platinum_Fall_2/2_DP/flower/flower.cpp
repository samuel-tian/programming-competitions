#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define INF INT_MAX
#define NINF INT_MIN
#define MAXF 100
#define MAXV 100

int f, v;
int aesthetic[MAXF][MAXV];
int dp[MAXF][MAXV];

int main() {
    cin >> f >> v;
    for (int i = 0; i < f; ++i) {
        for (int j = 0; j < v; ++j) {
            cin >> aesthetic[i][j];
        }
    }
    for (int i = 0; i < f; ++i) {
        for (int j = 0; j < v; ++j) {
            dp[i][j] = NINF;
        }
    }
    for (int i = 0; i < v; ++i) {
        dp[0][i] = aesthetic[0][i];
    }
    for (int i = 1; i < f; ++i) {
        for (int j = i; j < v; ++j) {
            for (int k = 0; k < j; ++k) {
                if (dp[i - 1][k] == NINF) continue;
                dp[i][j] = max(dp[i][j], dp[i - 1][k] + aesthetic[i][j]);
            }
            dp[i][j] = max(dp[i][j], dp[i][j - 1]);
        }
    }
    /*for (int i = 0; i < f; ++i) {
        for (int j = 0; j < v; ++j) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }*/
    cout << dp[f-1][v-1] << endl;
}
