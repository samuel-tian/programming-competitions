/*input
4
13
9
19
3
0
10
20
3
4
0
11
2
1
15
0
12
5
5
13
0
*/

#include <iostream>
#include <utility>
#include <climits>
#include <algorithm>

using namespace std;

#define INF INT_MAX
#define NINF INT_MIN
#define endl '\n'
#define MAXN 400

int N;
pair<int, int> P[MAXN+1];
int T[MAXN+1][MAXN];
int DP[MAXN+1];

int main() {
	cin >> N;
	for (int i = 1; i <= N; ++i) {
		int temp;
		cin >> temp;
		P[i] = make_pair(temp, i);
	}
	sort(P, P+N+1);
	// for (int i = 0; i < N+1; ++i) cout << P[i].second << ": " << P[i].first << endl;
	for (int i = 1; i <= N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> T[i][j];
		}
	}
	for (int i = 0; i < N; ++i) {
		T[0][i] = T[1][i];
	}

	fill(DP, DP+N+1, -1 );
	DP[0] = 0;

	for (int i = 0; i < N; ++i) {
		for (int j = i+1; j <= N; ++j) {
			if (DP[j] <= DP[i] && T[P[i].second][P[j].second-1] <= P[j].first - P[i].first) {
				DP[j] = DP[i] + 1;
				
				/*
				for (int i = 0; i < N+1; ++i) {
					cout << DP[i] << " ";
				}
				cout << endl;
				*/

			}
		}
	}



	cout << *max_element(DP, DP+N+1) << endl;;
}