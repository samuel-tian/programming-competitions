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

int maxlength = 0, n;
int grid[5][5];
void recurse(int left, int right, int r, int c, string current, int counter){
	/*cout << left sp right sp r sp c sp current << endl;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			cout << grid[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;*/
	if (right >= left){
		maxlength = max(maxlength, left * 2);
		return;
	}
	else{
		int dx[4] = {1, 0, -1, 0};
		int dy[4] = {0, 1, 0, -1};
		if (right > 0){
			for (int i = 0; i < 4; i++){
				int nr = r + dx[i];
				int nc = c + dy[i];
				if (nr<n && nr>=0 && nc<n && nc>=0 && grid[nr][nc]==')'){
					int store = grid[nr][nc];
					grid[nr][nc] = counter;
					recurse(left, right+1, nr, nc, current + ")", counter+1);
					grid[nr][nc] = store;
				}
			}
		}
		else{
			for (int i = 0; i < 4; i++){
				int nr = r + dx[i];
				int nc = c + dy[i];
				if (nr < n && nr >= 0 && nc < n && nc >= 0 && (grid[nr][nc]=='(' || grid[nr][nc]==')')){
					int store = grid[nr][nc];
					grid[nr][nc] = counter;
					if (store=='(') recurse(left + 1, right, nr, nc, current + "(", counter+1);
					else recurse(left, right+1, nr, nc, current + ")", counter+1);
					grid[nr][nc] = store;
				}
			}
		}
	}
	return;
}
int main(){
	cin >> n;
	string temp[n];
	for (int i = 0; i < n; i++){
		cin >> temp[i];
		for (int j = 0; j < n; j++){
			grid[i][j] = temp[i][j];
		}
	}
	if (grid[0][0]==')') cout << 0 << endl;
	else{
		grid[0][0] = 1;
		recurse(1, 0, 0, 0, "(", 2);
		cout << maxlength << endl;
	}
}