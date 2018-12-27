#include <iostream>
#include <climits>
#include <string>

using namespace std;

#define endl '\n'
#define MAXN 250
#define MAXP 200
#define INF INT_MAX
#define MOD 97654321
#define ascii(a) (a>='a'&&a<='z')?a-'a'+26:a-'A'

int u, l, p;
int dictionary[MAXP][2];
int dp[MAXN + 1][MAXN + 1][52];
// uppercase, lowercase, last letter
// uppercase letters are 0...25, lowercase letters are 26...51

int main() {
    cin >> u >> l >> p;
    for (int i = 0; i < p; ++i) {
        string s;
        cin >> s;
        dictionary[i][0] = ascii(s[0]);
        dictionary[i][1] = ascii(s[1]);
    }
    for (int i = 0; i < u; ++i) {
        for (int j = 0; j < l; ++j) {
            for (int k = 0; k < p; ++k) {
                dp[i][j][k] = 0;
            }
        }
    }
    for (int i = 0; i < 52; ++i) {
        if (i < 26) {
            dp[1][0][i] = 1;
        }
        else if (i >= 26) {
            dp[0][1][i] = 1;
        }
    }
    for (int i = 0; i <= u; ++i) {
        for (int j = 0; j <= l; ++j) {
            if (i + j <= 1) continue;
            for (int k = 0; k < p; ++k) {
                if (dictionary[k][1] < 26 && i != 0) {
                    dp[i][j][dictionary[k][1]] = (dp[i][j][dictionary[k][1]] + dp[i - 1][j][dictionary[k][0]]) % MOD;
                }
                else if (dictionary[k][1] >= 26 && j != 0){
                    dp[i][j][dictionary[k][1]] = (dp[i][j][dictionary[k][1]] + dp[i][j - 1][dictionary[k][0]]) % MOD;
                }
            }
        }
    }
    long long ret = 0;
    for (int i = 0; i < 52; ++i) {
        ret = (ret + dp[u][l][i]) % MOD;
    }
    cout << ret << endl;
}
