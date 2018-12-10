#include <bits/stdc++.h>  //includes everything, supported in CF, usaco, not POJ
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
using namespace std;
 
typedef pair<int, int> pii;
typedef vector<pii> vii;

int main(){                             // USACO
  	int rows, cols; cin >> rows >> cols;
  	pii moves; cin >> moves.f >> moves.s;
  	pii start, end;
  	int pond[rows][cols];
  	int dist[rows][cols];
  	for (int i = 0; i < rows; i++){
    	for (int j = 0; j < cols; j++){
      	cin >> pond[i][j];
      	if (pond[i][j]==2) pond[i][j] = 0;
      	if (pond[i][j]==3) start = mp(i, j);
      	if (pond[i][j]==4){
        	end = mp(i, j);
        	pond[i][j] = 1;
      	}
      
      	dist[i][j] = inf;
    	}
  	}
  	dist[start.f][start.s] = 0;
  	queue<pii> q;
  	q.push(start);
  	while(!q.empty()){
    	pii current = q.front();
    	q.pop();
    	if (current==end) continue;
    	int dx[8] = {moves.f, -moves.f, moves.f, -moves.f, moves.s, -moves.s, moves.s, -moves.s};
    	int dy[8] = {-moves.s, -moves.s, moves.s, moves.s, -moves.f, -moves.f, moves.f, moves.f};
    	for (int i = 0; i < 8; i++){
      		pii next = mp(current.f + dx[i], current.s + dy[i]);
      		if (next.f>=0 && next.f<rows && next.s>=0 && next.s<cols && pond[next.f][next.s]!=0){
        		if (dist[current.f][current.s] + 1 < dist[next.f][next.s]){
          			dist[next.f][next.s] = dist[current.f][current.s] + 1;
          			q.push(next);
        		}
      		}
    	}
  	}
  	cout << dist[end.f][end.s] << endl;
}