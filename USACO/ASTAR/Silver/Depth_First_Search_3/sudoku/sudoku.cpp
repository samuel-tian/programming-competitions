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


int ans[9][9];
int board[9][9];
void sudoku(int r, int c){
	if (r==9){
		for (int i = 0; i < 9; i++){
			for (int j = 0; j < 9; j++){
				ans[i][j] = board[i][j];
			}
		}
		return;
	}
	int nr = r, nc = c;
	nc++;
	if (nc==9){
		nr++;
		nc = 0;
	}
	if (board[r][c] != 0){
		sudoku(nr, nc);
		return;
	}
	for (int i = 1; i <= 9; i++){
		bool b = true;
		for (int j = 0; j < 9; j++){
			if (board[r][j]==i || board[j][c]==i){
				b = false;
				break;
			}
			if (b == false) break;
		}
		for (int rr = (r/3)*3; rr < (r/3)*3+3; rr++){
			for (int cc = (c/3)*3; cc < (c/3)*3+3; cc++){
				if (b == false) break;
				if (board[rr][cc] == i){
					b = false;
					break;
				}
				
			}
			if (b == false) break;
		}
		if (b == true){
			board[r][c] = i;
			sudoku(nr, nc);
			board[r][c] = 0;
		}
		
	}
}
int main(){														 // USACO
	for (int i = 0; i < 9; i++){
		for (int j = 0; j < 9; j++){
			cin >> board[i][j];
		}
	}
	sudoku(0,0);
	int filled = true;
	for (int i = 0; i < 9; i++){
		for (int j = 0; j < 9; j++){
			if (ans[i][j]==0){
				filled = false;
				break;
			}
		}
		if (filled == false) break;
	}
	if (filled == true){
		for (int i = 0; i < 9; i++){
			for (int j = 0; j < 9; j++){
				cout << ans[i][j] << " ";
			}
			cout << endl;
		}
	}
	else cout << "NO SOLUTION" << endl;
}