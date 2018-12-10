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

int main(){														 // USACO
	int rows, cols; cin >> rows >> cols;
	string temp[rows];
	char maze[rows][cols];
	int dist[rows][cols];
	pii start, end;
	pii teleport1[26], teleport2[26];
	for (int i = 0; i < rows; i++) cin >> temp[i];
	bool firsttele[26];
	for (int i = 0; i < rows; i++){
		for (int j = 0; j < cols; j++){
			maze[i][j] = temp[i][j];
			if (maze[i][j]=='@') start = mp(i, j);
			if (maze[i][j]=='=') end = mp(i, j);
			
			if (maze[i][j]>='A' && maze[i][j]<='Z'){
				if (firsttele[maze[i][j] - 'A'] == false){
					teleport1[maze[i][j] - 'A'] = mp(i, j);
					firsttele[maze[i][j] - 'A'] = true;
				}
				else{
					teleport2[maze[i][j] - 'A'] = mp(i, j);
					firsttele[maze[i][j] - 'A'] = false;
				}
			}
			dist[i][j] = inf;
		}
	}
	dist[start.f][start.s] = 0;
	queue<pii> q;
	q.push(start);
	while (!q.empty()){
		
		pii current = q.front();
		
		q.pop();
		if (maze[current.f][current.s]=='=') continue;
		int dx[4] = {1, 0, -1, 0};
		int dy[4] = {0, -1, 0, 1};
		
		for (int i = 0; i < 4; i++){
			pii next(current.f+dx[i], current.s+dy[i]);
			if (next.f<rows && next.f>=0 && next.s<cols && next.s>=0 && maze[next.f][next.s]!='#'){
				if (maze[next.f][next.s]>='A' && maze[next.f][next.s]<='Z'){
					if (teleport1[maze[next.f][next.s] - 'A'] == mp(next.f, next.s)){
						next = mp(teleport2[maze[next.f][next.s] - 'A'].f, teleport2[maze[next.f][next.s] - 'A'].s);
					}
					else{
						next = mp(teleport1[maze[next.f][next.s] - 'A'].f, teleport1[maze[next.f][next.s] - 'A'].s);
					}
				}
				if (dist[current.f][current.s]+1 < dist[next.f][next.s]){
					q.push(next);
					dist[next.f][next.s] = dist[current.f][current.s]+1;
				}
			}
		}
	}
	cout << dist[end.f][end.s] << endl;
}