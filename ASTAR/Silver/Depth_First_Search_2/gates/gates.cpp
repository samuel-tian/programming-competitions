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
#define debug cout << "pass" << endl;
// #define bitSize 262144	/*smallest pow of 2 bigger than size of array */
// #define bitSize2 bitSize*2
using namespace std;
 
typedef pair<int, int> pii;
typedef vector<pii> vii;

bool grid[2001][2001]; // dimensions should be doubled...
int main(){
	
	int r = 1000, c = 1000;
	grid[r][c] = true;
	int n; cin >> n;
	string dir; cin >> dir;
	for (int i = 0; i < n; i++){
		if (dir[i] == 'N'){
			grid[r-1][c] = true;
			grid[r-2][c] = true;
			r -= 2;
		}
		if (dir[i] == 'S'){
			grid[r+1][c] = true;
			grid[r+2][c] = true;
			r += 2;
		}
		if (dir[i] == 'E'){
			grid[r][c+1] = true;
			grid[r][c+2] = true;
			c += 2;
		}
		if (dir[i] == 'W'){
			grid[r][c-1] = true;
			grid[r][c-2] = true;
			c -= 2;
		}
	}
	int counter = 0;
	for (int i = 0; i < 2001; i++){
		for (int j = 0; j < 2001; j++){
			if (grid[i][j] == true) continue;
			counter++;
			queue<pii> q;
			q.push(mp(i, j));
			while (!q.empty()){
				pii current = q.front();
				q.pop();
				int dx[4] = {1, -1, 0, 0};
				int dy[4] = {0, 0, 1, -1};
				for (int i = 0; i < 4; i++){
					pii next = mp(current.f + dx[i], current.s + dy[i]);
					if (next.f>=0 && next.f<2001 && next.s>=0 && next.s<2001 && grid[next.f][next.s]==false){
						grid[next.f][next.s] = true;
						q.push(next);
					}
				}
			}
		}
	}
	cout << counter-1 << endl;
}