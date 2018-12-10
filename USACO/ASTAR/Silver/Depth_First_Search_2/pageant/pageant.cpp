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

char grid[50][50];
int rows, cols;
void floodfill(int row, int col, char fillchar){
	if (grid[row][col]!='X' || col<0 || col>=cols || row<0 || row>=rows) return;
	grid[row][col] = fillchar;
	int dx[4] = {1, 0, -1, 0};
	int dy[4] = {0, -1, 0, 1};
	for (int i = 0; i < 4; i++){
		floodfill(row+dx[i], col+dy[i], fillchar);
	}
	return;
}
int main(){														 // USACO
	cin >> rows >> cols;
	string temp[rows];
	string input;
	for (int i = 0; i < rows; i++){
		cin >> input;
		temp[i] = input;
	}
	for (int j = 0; j < rows; j++){
		for (int k = 0; k < cols; k++){
			grid[j][k] = temp[j][k];
		}
	}
	bool tempbool = false;
	for (int i = 0; i < rows; i++){
		for (int j = 0; j < cols; j++){
			if (grid[i][j]=='X'){
				floodfill(i, j, 'a');
				tempbool = true;
			}
			if (tempbool == true) break;
		}
		if (tempbool == true) break;
	}
	tempbool = false;
	for (int i = 0; i < rows; i++){
		for (int j = 0; j < cols; j++){
			if (grid[i][j]=='X'){
				floodfill(i, j, 'b');
				tempbool = true;
			}
			if (tempbool == true) break;
		}
		if (tempbool == true) break;
	}
	int mindistance = inf;
	int distance;
	for (int i = 0; i < rows; i++){
		for (int j = 0; j < cols; j++){
			for (int a = 0; a < rows; a++){
				for (int b = 0; b < cols; b++){
					if (grid[i][j]=='a' && grid[a][b]=='b'){
						distance = abs((abs(i - a) + abs(j - b)))-1;
						if (distance < mindistance){
							mindistance = distance;
						}
					}
				}
			}
		}
	}
	cout << mindistance << endl;
}