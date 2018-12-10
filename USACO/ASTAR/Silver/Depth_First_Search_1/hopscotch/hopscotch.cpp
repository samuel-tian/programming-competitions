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

char grid[15][15];
int rows, cols;
int recurse(int r, int c, char color){
	int count = 0;
	if (r==rows-1 && c==cols-1) return 1;
	else{
		for (int i = r+1; i<rows; i++){
			for (int j = c+1; j<cols; j++){
				if (grid[i][j]!=grid[r][c]){
					count += recurse(i, j, grid[i][j]);
				}
			}
		}
		return count;
	}
}
int main(){														 // USACO
	cin >> rows >> cols;
	string temp[rows];
	for (int i = 0; i < rows; i++){
		cin >> temp[i];
	}
	for (int i = 0; i < rows; i++){
		for (int j = 0; j < cols; j++){
			grid[i][j] = temp[i][j];

		}

	}
	cout << recurse(0, 0, grid[0][0]) << endl;
}