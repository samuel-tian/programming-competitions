#include <bits/stdc++.h>	//includes everything, supported in CF, usaco, not POJ
#define DEBUG
#define f first
#define s second
#define pb push_back
#define ll long long
#define mp make_pair
#define endl '\n'
#define sp << ' ' <<
#define inf 2000000000
#define p 1000000007
#define eps 1e-9
#define maxn 100010
// #define bitSize 262144	/*smallest pow of 2 bigger than size of array */
// #define bitSize2 bitSize*2
using namespace std;
 
typedef pair<int, int> pii;
typedef vector<pii> vii;

int main(){
	int x, y; cin >> y >> x;
	string map[x];
	int dist[x][y];
	pii start, end;
	for (int i = 0; i < x; i++){
		cin >> map[i];
		for (int j = 0; j < y; j++){
			if (map[i][j]=='K') start = mp(i, j);
			if (map[i][j]=='H') end = mp(i, j);
			dist[i][j] = inf;
		}
	}
	dist[start.f][start.s] = 0;
	queue<pii> q;
	q.push(start);
	while (!q.empty()){
		/*for (int i = 0; i < x; i++){
			for (int j = 0; j < y; j++){
				cout << dist[i][j] << " ";
			}
			cout << endl;
		}*/
		//cout << endl;
		pii current = q.front();
		q.pop();
		if (current == end) continue;
		int dx[8] = {2, 2, -2, -2, 1, 1, -1, -1};
		int dy[8] = {1, -1, 1, -1, 2, -2, 2, -2};
		for (int i = 0; i < 8; i++){
			pii next = mp(current.f+dx[i], current.s+dy[i]);
			if (next.f>=0 && next.f<x && next.s>=0 && next.s<y && map[next.s][next.f]!='*'){
				if (dist[current.f][current.s]+1 < dist[next.f][next.s]){
					dist[next.f][next.s] = dist[current.f][current.s]+1;
					q.push(next);
				}
			}
		}
	}
	cout << dist[end.f][end.s] << endl;
}