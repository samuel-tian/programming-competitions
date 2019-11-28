//
// Created by Samuel on 11/18/2019.
//

/*
 * Convex Hull Trick
 * -----------------
 * dynamic programming optimization that computes transitions of the form mx+b
 */

#include <bits/stdc++.h>

using namespace std;

#define INF INT_MAX
#define endl '\n'
#define MAXN 50000

long long n;
vector<pair<long long, long long> > params;
long long dp[MAXN + 1];

double intersect(pair<long long, long long> a, pair<long long, long long> b) {
	return ((double)(b.first - a.first)) / (a.second - b.second);
}

double eval(pair<long long, long long> a, long long x) {
	return a.first + a.second * x;
}

long long convexHullTrick() {
	dp[0] = 0;
	deque<pair<long long, long long> > lines; // (b, m)
	n = params.size();
	for (long long i = 1; i <= n; ++i) {
		pair<long long, long long> insertLine = make_pair(dp[i - 1], params[i - 1].second);
		while (lines.size() >= 2) {
			if (intersect(lines[lines.size() - 1], insertLine) <= intersect(lines[lines.size() - 2], insertLine)) {
				lines.pop_back();
			}
			else {
				break;
			}
		}
		lines.push_back(insertLine);
		long long counter = lines.size() - 1;
		while (counter >= 1 && eval(lines[counter], params[i - 1].first) > eval(lines[counter - 1], params[i - 1].first)) {
			--counter;
		}
		dp[i] = (long long) eval(lines[counter], params[i - 1].first);
		/*for (long long j = 0; j < lines.size(); ++j) {
			cout << "(" << lines[j].first << ", " << lines[j].second << ")" << " ";
		}
		cout << endl;*/
	}
	/*for (long long i = 0; i <= n; ++i) {
		cout << dp[i] << " ";
	}
	cout << endl;*/
	return dp[n];
}

int main() {
//	freopen("input.txt", "r", stdin);
	cin >> n;
	for (long long i = 0; i < n; ++i) {
		long long a, b;
		cin >> a >> b;
		params.emplace_back(a, b);
	}
	sort(params.begin(), params.end());
	for (long long i = n - 2; i >= 0; --i) {
		if (params[i].second <= params[i + 1].second) {
			params.erase(params.begin() + i);
		}
	}
	/*for (long long j = 0; j < params.size(); ++j) {
			cout << "(" << params[j].first << ", " << params[j].second << ")" << " ";
		}
	cout << endl;*/
	cout << convexHullTrick() << endl;
}