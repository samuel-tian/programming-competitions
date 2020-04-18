/*input
2 2000000000
*/

/*
12 = 1100
2 = 10
*/

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>

using namespace std;

#define endl '\n'
#define INF INT_MAX

int dp[2][32][32];

int recurse(string targetString) {
	for (int i = 0; i < 2; ++i) {
		for (int j = 0; j < 32; ++j) {
			for (int k = 0; k < 32; ++k) {
				dp[i][j][k] = 0;
			}
		}
	}
	dp[1][0][1] = 1;
	for (int i = 1; i >= 0; --i) {
		for (int j = 0; j < targetString.size(); ++j) {
			for (int k = 0; j + k < targetString.size(); ++k) {
				if (dp[i][j][k] == 0) continue;
				if (i == 0) {
					dp[i][j + 1][k] += dp[i][j][k];
					dp[i][j][k + 1] += dp[i][j][k];
				}
				else {
					if (targetString[j + k] == '0') {
						dp[i][j + 1][k] += dp[i][j][k];
					}
					else {
						dp[i - 1][j + 1][k] += dp[i][j][k];
						dp[i][j][k + 1] += dp[i][j][k];
					}
				}
			}
		}
	}
	int ret = 0;
	for (int i = 0; i < 2; ++i) {
		for (int j = 0; j <= targetString.size(); ++j) {
			for (int k = 0; k <= targetString.size(); ++k) {
				if (j >= k && j + k == targetString.size()) {
					ret += dp[i][j][k];
					/*if (dp[i][j][k] > 0) {
						cout << i << " " << j << " " << k << endl;
					}*/
				}
			}
		}
	}
	// cout << ret << endl;
	/*for (int i = 0; i < 2; ++i) {
		for (int j = 0; j <= targetString.size(); ++j) {
			for (int k = 0; k <= targetString.size(); ++k) {
				cout << dp[i][j][k] << " ";
			}
			cout << endl;
		}
		cout << endl;
	}*/
	return ret;
}

string toBinaryString(int num) {
	string ret = "";
	while (num > 0) {
		ret = to_string(num % 2) + ret;
		num >>= 1;
	}
	return ret;
}

int total(int n) {
	int ret = 0;
	string strn = toBinaryString(n);
	for (int i = 1; i < strn.size(); ++i) {
		int a = (1 << i) - 1;
		// cout << a << endl;
		ret += recurse(toBinaryString(a));
	}
	ret += recurse(strn);
	return ret;
}

int main() {
	int start, finish;
	cin >> start >> finish;
	// cout << toBinaryString(finish) << " " << toBinaryString(start - 1) << endl;
	cout << total(finish) - total(start - 1) << endl;
	return 0;
}