/*input
100 1000000000000000000
*/

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

#define endl '\n'
#define INF INT_MAX

long long dp[2][10][20][20];
/*
dp[x] is lo
dp[x][x] is repeated digit
dp[x][x][x] is number of repeated digit
dp[x][x][x][x] is number of other digit
*/
long long cdp[2][20][20];
/*
cdp[x] is lo
cdp[x][x] is number of first digit
cdp[x][x][x] is number of second digit
*/

long long recurse(string targetString) {
	for (long long i = 0; i < 2; ++i) {
		for (long long j = 0; j < 10; ++j) {
			for (long long k = 0; k < 20; ++k) {
				for (long long l = 0; l < 20; ++l) {
					dp[i][j][k][l] = 0;
				}
			}
		}
	}
	for (long long i = 1; i < targetString[0] - '0'; ++i) {
		for (long long j = 0; j < 10; ++j) {
			if (i == j) {
				++dp[0][j][1][0];
			}
			else {
				++dp[0][j][0][1];
			}
		}
	}
	for (long long i = 0; i < 10; ++i) {
		if (i == targetString[0] - '0') {
			++dp[1][i][1][0];
		}
		else {
			++dp[1][i][0][1];
		}
	}
	/*for (long long i = 0; i < 2; ++i) {
		cout << "i: " << i << endl << "----" << endl;
		for (long long j = 0; j < 10; ++j) {
			cout << "j: " << j << endl;
			for (long long k = 0; k <= targetString.size(); ++k) {
				for (long long l = 0; l <= targetString.size(); ++l) {
					cout << dp[i][j][k][l] << " ";
				}
				cout << endl;
			}
			cout << endl;
		}
	}*/
	for (long long i = 1; i >= 0; --i) {
		for (long long j = 0; j < 10; ++j) {
			for (long long k = 0; k <= targetString.size(); ++k) {
				for (long long l = 0; k + l <= targetString.size(); ++l) {
					if (dp[i][j][k][l] == 0) continue;
					if (i == 0) {
						for (long long n = 0; n < 10; ++n) {
							if (n == j) {
								dp[i][j][k + 1][l] += dp[i][j][k][l];
							}
							else {
								dp[i][j][k][l + 1] += dp[i][j][k][l];
							}
						}
					}
					else {
						for (long long n = 0; n < targetString[k + l] - '0'; ++n) {
							if (n == j) {
								dp[i - 1][j][k + 1][l] += dp[i][j][k][l];
							}
							else {
								dp[i - 1][j][k][l + 1] += dp[i][j][k][l];
							}
						}
						if (targetString[k + l] - '0' == j) {
							dp[i][j][k + 1][l] += dp[i][j][k][l];
						}
						else {
							dp[i][j][k][l + 1] += dp[i][j][k][l];
						}
					}
				}
			}
		}
	}
	long long ret = 0;
	for (long long i = 0; i < 2; ++i) {
		for (long long j = 0; j < 10; ++j) {
			for (long long k = 0; k <= targetString.size(); ++k) {
				for (long long l = 0; l <= targetString.size(); ++l) {
					if (k >= l && k + l == targetString.size()) {
						ret += dp[i][j][k][l];
					}
				}
			}
		}
	}
	/*for (long long i = 0; i < 2; ++i) {
		cout << "i: " << i << endl << "----" << endl;
		for (long long j = 0; j < 10; ++j) {
			cout << "j: " << j << endl;
			for (long long k = 0; k <= targetString.size(); ++k) {
				for (long long l = 0; l <= targetString.size(); ++l) {
					cout << dp[i][j][k][l] << " ";
				}
				cout << endl;
			}
			cout << endl;
		}
	}*/
	return ret;
}

long long repeat(string targetString) {
	long long ret = 0;
	long long starting = targetString[0] - '0';
	for (long long f = 0; f <= starting; ++f) {
		for (long long s = f + 1; s < 10; ++s) {
			for (long long i = 0; i < 2; ++i) {
				for (long long j = 0; j < 20; ++j) {
					for (long long k = 0; k < 20; ++k) {
						cdp[i][j][k] = 0;
					}
				}
			}
			if (f == 0) {
				if (starting == s) {
					++cdp[1][0][1];
				}
				else if (starting > s) {
					++cdp[0][0][1];
				}
				else {
					continue;
				}
			}
			else {
				if (starting == f) {
					++cdp[1][1][0];
				}
				else if (starting > f && starting < s) {
					++cdp[0][1][0];
				}
				else if (starting == s) {
					++cdp[0][1][0];
					++cdp[1][0][1];
				}
				else {
					++cdp[0][1][0];
					++cdp[0][0][1];
				}
			}
			for (long long i = 1; i >= 0; --i) {
				for (long long j = 0; j < targetString.size(); ++j) {
					for (long long k = 0; j + k < targetString.size(); ++k) {
						if (cdp[i][j][k] == 0) continue;
						if (i == 0) {
							cdp[i][j + 1][k] += cdp[i][j][k];
							cdp[i][j][k + 1] += cdp[i][j][k];
						}
						else {
							long long next = targetString[j + k] - '0';
							if (next == f) {
								cdp[i][j + 1][k] += cdp[i][j][k];
							}
							else if (next > f && next < s) {
								cdp[i - 1][j + 1][k] += cdp[i][j][k];
							}
							else if (next == s) {
								cdp[i - 1][j + 1][k] += cdp[i][j][k];
								cdp[i][j][k + 1] += cdp[i][j][k];
							}
							else if (next > s) {
								cdp[i - 1][j + 1][k] += cdp[i][j][k];
								cdp[i - 1][j][k + 1] += cdp[i][j][k];
							}
						}
					}
				}
			}
			for (long long i = 0; i < 2; ++i) {
				for (long long j = 0; j <= targetString.size(); ++j) {
					for (long long k = 0; k <= targetString.size(); ++k) {
						if (j == k && j + k == targetString.size()) {
							ret += cdp[i][j][k];
						}
					}
				}
			}
		}
	}
	// cout << "ret: " << ret << endl;
	return ret;
}

long long total(long long n) {
	long long ret = 0;
	string strn = to_string(n);
	for (long long i = 1; i < strn.size(); ++i) {
		long long a = 1;
		for (long long j = 0; j < i; ++j) {
			a *= 10;
		}
		ret += recurse(to_string(a - 1)) - repeat(to_string(a - 1));
	}
	ret += recurse(strn) - repeat(strn);
	return ret;
}

int main() {
	long long s, f;
	cin >> s >> f;
	cout << total(f) - total(s - 1) << endl;
	// cout << "Recurse: " << recurse(to_string(f)) - recurse(to_string(s - 1)) << endl;
	// cout << "Repeat: " << repeat(to_string(f)) - repeat(to_string(s - 1)) << endl;
	return 0;
}