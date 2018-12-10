/*input
20 30 300
4 5 5 4 4 2 3 3 3 2 2 3 2 1 1 1 2 1 2 1 1 2 3 4 3 3 4 5 5 3
6 8 8 6 5 3 5 5 4 2 2 4 3 2 2 2 3 2 3 3 2 4 5 7 6 5 5 5 6 4
5 7 7 7 6 4 4 3 3 3 4 5 4 4 5 4 3 2 3 5 4 5 5 6 7 6 5 4 5 4
4 6 7 7 7 5 4 2 3 3 4 4 4 5 6 5 3 2 4 7 6 5 4 4 5 5 4 3 3 3
4 5 5 6 7 6 4 3 4 4 5 5 6 6 7 5 4 2 4 5 6 4 3 2 4 6 6 5 3 2
5 6 6 6 6 5 4 4 5 4 6 5 5 3 4 3 4 2 3 2 4 3 4 4 5 6 5 4 2 1
4 5 5 6 5 4 3 4 5 4 6 6 6 4 4 4 6 5 4 2 3 4 4 5 5 7 6 5 2 0
2 3 5 7 7 4 3 2 5 4 7 6 6 5 4 4 5 6 6 4 3 3 4 5 5 6 5 4 1 0
1 2 3 5 6 5 4 2 4 3 5 4 5 6 5 5 5 6 7 5 4 3 3 4 5 7 6 5 3 2
2 3 4 4 6 5 6 4 5 3 4 4 6 6 5 4 5 5 7 4 5 3 5 5 7 8 7 6 5 4
3 5 5 4 5 5 6 4 4 2 3 4 6 6 5 5 5 4 5 3 5 4 6 6 6 6 5 5 5 4
3 6 8 7 6 5 6 6 6 3 3 5 7 6 4 5 6 5 4 2 3 4 6 6 4 4 5 5 5 3
3 5 6 7 6 6 6 7 7 4 3 3 5 5 4 5 5 4 2 1 2 3 5 4 3 2 4 4 5 3
3 5 6 6 5 5 5 6 7 5 4 3 5 5 5 5 5 4 2 1 1 2 3 2 3 3 6 5 6 3
2 3 4 4 5 5 5 5 6 6 6 5 6 5 5 5 4 3 1 1 1 2 3 2 3 3 6 5 6 3
2 4 5 3 4 4 4 2 4 5 6 6 7 7 5 5 3 3 2 2 2 3 3 3 2 4 6 5 5 2
2 3 5 4 6 5 5 4 6 7 7 6 6 5 4 4 4 4 3 3 4 6 6 5 2 4 6 6 6 3
3 5 6 5 6 4 5 4 6 5 4 3 4 5 5 5 5 6 5 5 5 7 7 7 5 5 5 4 4 2
2 4 5 5 6 4 6 6 8 6 4 2 2 3 4 4 5 7 7 6 4 5 5 5 4 3 4 3 4 2
1 3 3 3 3 2 4 4 5 3 1 0 0 2 2 3 3 5 5 4 2 2 2 3 3 2 2 1 2 1
*/
#include <bits/stdc++.h>
#define f first
#define s second
#define pb push_back
#define ll long long
#define mp make_pair
#define endl '\n'
#define sp << ' ' <<
#define inf 2000000000
#define MAXN 30
#define MAXM 30
using namespace std;
typedef pair<int, int> pii;
typedef vector<pii> vii;

int n, m, k;
int surroundings[MAXN][MAXM];
bool mines[MAXN][MAXM];
bool solfound = false;
int dx[9] = {1, 1, 1, 0, 0, 0, -1, -1, -1};
int dy[9] = {1, 0, -1, 1, 0, -1, 1, 0, -1};
void print_grid(){
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			cout << surroundings[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}
bool check(){
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (surroundings[i][j] != 0)
				return false;
	return true;
}
bool possible_mine(int r, int c){
	for (int i = 0; i < 9; i++){
		int nr = r+dx[i]; int nc = c+dy[i];
		if (surroundings[nr][nc] == 0 && nr>=0 && nr<n && nc>=0 && nc<m)
			return false;
	}
	return true;
}
void put_mine(int r, int c){
	for (int i = 0; i < 9; i++){
		int nr = r+dx[i]; int nc = c+dy[i];
		if (nr>=0 && nr<n && nc>=0 && nc<m){
			surroundings[nr][nc]--;
		}
	}
	mines[r][c] = true;
	return;
}
void rm_mine(int r, int c){
	for (int i = 0; i < 9; i++){
		int nr = r+dx[i]; int nc = c+dy[i];
		if (nr>=0 && nr<n && nc>=0 && nc<m){
			surroundings[nr][nc]++;
		}
	}
	mines[r][c] = false;
	return;
}
void recurse(int r, int c, int remmines, int remsquares){
	if (solfound == true) return;
	if (remmines < 0) return;
	if (remmines == 0){
		if (check()){
			// cout << r sp c << endl;
			for (int i = 0; i < n; i++)
				for (int j = 0; j < m; j++)
					if (mines[i][j] == true)
						cout << i+1 sp j+1 << endl;
			solfound = true;
		}
		return;
	}
	if (r>=1 && c>=2 && surroundings[r-1][c-2]>0) return;
	if (r>=2 && c==0 && (surroundings[r-2][c+n-1]!=0 || surroundings[r-2][c+n-2]!=0)) return;
	if (remmines > remsquares) return;

	int nr = r; int nc = c;
	if (c == m-1) {nr = r + 1; nc = 0;}
	else {nr = r; nc = c + 1;}
	while (mines[nr][nc] == 1){
		if (nc == m-1) {nr = nr + 1; nc = 0;}
		else {nr = nr; nc = nc + 1;}
	}
	if (possible_mine(r, c)){
		put_mine(r, c);
		recurse(nr, nc, remmines-1, remsquares-1);
		rm_mine(r, c);
	}
	if (remmines < remsquares)
		recurse(nr, nc, remmines, remsquares-1);
	return;
}
int main(){
	cin >> n >> m >> k;
	int remsquares = n*m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> surroundings[i][j];
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			if (surroundings[i][j] == 9){
				for (int ii = 0; ii < 9; ii++){
					put_mine(i+dx[ii], j+dy[ii]);          
					k--; remsquares--;
				}
			}
		}
	}
	for (int i = 0; i < n; i++){
		if (surroundings[i][0] == 6){
			for (int ii = 0; ii < 9; ii++){
				int nr = i+dx[ii]; int nc = dy[ii];
				if (nr>=0 && nr<n && nc>=0 && nc<m){
					put_mine(nr, nc);
					k--; remsquares--;
				}
			}
		}
		if (surroundings[i][m-1] == 6){
			for (int ii = 0; ii < 9; ii++){
				int nr = i+dx[ii]; int nc = m-1+dy[ii];
				if (nr>=0 && nr<n && nc>=0 && nc<m){
					put_mine(nr, nc);
					k--; remsquares--;
				}
			}
		}
	}
	for (int j = 0; j < m; j++){
		if (surroundings[0][j] == 6){
			for (int ii = 0; ii < 9; ii++){
				int nr = dx[ii]; int nc = j+dy[ii];
				if (nr>=0 && nr<n && nc>=0 && nc<m){
					put_mine(nr, nc);
					k--; remsquares--;
				}
			}
		}
		if (surroundings[n-1][j] == 6){
			for (int ii = 0; ii < 9; ii++){
				int nr = n-1+dx[ii]; int nc = j+dy[ii];
				if (nr>=0 && nr<n && nc>=0 && nc<m){
					put_mine(nr, nc);
					k--; remsquares--;
				}
			}
		}
	}
	//print_grid();
	//cout << k sp remsquares << endl;
	recurse(0, 0, k, remsquares);
	if (solfound == false) cout << "NO SOLUTION" << endl;
}