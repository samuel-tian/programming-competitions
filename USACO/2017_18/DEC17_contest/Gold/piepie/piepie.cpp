#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define MAXN 100000
#define INF INT_MAX

int n, d;
int dist[4*MAXN];
vector<pair<int,int> > bessie;
vector<pair<int,int> > elsie;
vector<int> borig;
vector<int> eorig;
vector<pair<int,int> > adj[4*MAXN];

int main() {
	freopen("output.txt", "w", stdout);
	ifstream ifs ("5.out", ios::in);
	int a;
	while (ifs >> a) {
		cout << a << " ";
	}
	cout << endl;
	ifs.close();
	freopen("5.in", "r", stdin);
	cin >> n >> d;
	int b, e;
	for (int i = 0; i < 2*n; ++i) {
		cin >> b >> e;
		bessie.emplace_back(b, i);
		elsie.emplace_back(e, i+2*n);
		borig.push_back(b);
		eorig.push_back(e);
//		adj[i].emplace_back(i+2*n, 0);
//		adj[i+2*n].emplace_back(i, 0);
	}
	sort(bessie.begin(), bessie.end());
	sort(elsie.begin(), elsie.end());
	for (int i = 0; i < 2 * n; ++i) {
		/*auto biter = lower_bound(elsie.begin(), elsie.end(), make_pair(eorig[i], 0));
		auto uiter = upper_bound(elsie.begin(), elsie.end(), make_pair(eorig[i] + d, INF));
		for (auto j = biter; j != uiter; ++j) {
			if ((*j).first < eorig[i] || (*j).first > eorig[i] + d) continue;
			adj[(*j).second].emplace_back(i, 1);
			if (i == 7) cout << "first" << endl;
		}
		biter = lower_bound(bessie.begin(), bessie.end(), make_pair(borig[i], 0));
		uiter = upper_bound(bessie.begin(), bessie.end(), make_pair(borig[i] + d, INF));
		for (auto j = biter; j != uiter; ++j) {
			if ((*j).first < borig[i] || (*j).first > borig[i] + d) continue;
			adj[(*j).second].emplace_back(i+2*n, 1);
			if (i+2*n == 7) cout << borig[i] << endl;
		}*/
		auto biter = lower_bound(bessie.begin(), bessie.end(), make_pair(borig[i], 0));
		auto uiter = upper_bound(bessie.begin(), bessie.end(), make_pair(borig[i] + d, INF));
		for (auto j = biter; j != uiter; ++j) {
			int otherval = j->second + 2*n;
			if (j->first < borig[i] || j->first > borig[i] + d) continue;
			adj[otherval].emplace_back(i, 1);
		}

		biter = lower_bound(elsie.begin(), elsie.end(), make_pair(eorig[i], 0));
		uiter = upper_bound(elsie.begin(), elsie.end(), make_pair(eorig[i] + d, INF));
		for (auto j = biter; j != uiter; ++j) {
			int otherval = j->second - 2*n;
			if (j->first < eorig[i] || j->first > eorig[i] + d) continue;
			adj[otherval].emplace_back(i+2*n, 1);
		}
	}
	fill(dist, dist+4*n, -1);
	queue<int> q;
	for (int i = 0; i < 2*n; ++i) {
		if (borig[i] == 0) {
			q.push(i);
			dist[i] = 0;
		}
		if (eorig[i] == 0) {
			q.push(i + 2*n);
			dist[i + 2*n] = 0;
		}
	}
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		for (int i = 0; i < adj[cur].size(); ++i) {
			int next = adj[cur][i].first;
			int weight = adj[cur][i].second;
//			if (abs(next - cur) == 2*n && weight == 1) continue;
			if (dist[next] == -1 || dist[cur] + weight < dist[next]) {
				dist[next] = dist[cur] + weight;
				q.push(next);
			}
		}
	}
//	for (int i = 0; i < 4 * n; ++i) {
//		for (int j = 0; j < adj[i].size(); ++j) {
//			cout << "(" << adj[i][j].first << " " << adj[i][j].second << ")" << " ";
//		}
//		cout << endl;
//	}
cout << endl;
	for (int i = 0; i < n; ++i) {
		cout << dist[i] << " ";
	}
	cout << endl;
	fclose(stdin);
}
