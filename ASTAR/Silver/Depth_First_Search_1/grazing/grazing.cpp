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

int field[5][5];
int recurse(int r, int c){
	int count = 0;
	if (r==4 && c==4){
		bool allfilled = true;
		for (int i = 0; i < 5; i++){
			for (int j = 0; j < 5; j++){
				if (field[i][j] == 0) allfilled = false;
			}
		}
		if (allfilled == true) return 1;
		else return 0;
	}
	else{
		int dx[4] = {1, 0, -1, 0};
		int dy[4] = {0, -1, 0, 1};
		for (int i = 0; i < 4; i++){
			if (r+dy[i]>=0 && r+dy[i]<5 && c+dx[i]>=0 && c+dx[i]<5 && field[r+dy[i]][c+dx[i]]==0){
				field[r+dy[i]][c+dx[i]]=1;
				//cout << "(" << r+dy[i] << ", " << c+dx[i] << ")" << endl;
				/*for (int a = 0; a < 5; a++){
					for (int b = 0; b < 5; b++){
						cout << field[a][b];
					}
					cout << endl;
				}*/
				count += recurse(r+dy[i], c+dx[i]);
				field[r+dy[i]][c+dx[i]]=0;
			}
		}
		return count;
	}
	
}
int main(){														 // USACO
	int n, xcor, ycor;
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> xcor >> ycor;
		field[xcor-1][ycor-1] = 1;
	}
	field[0][0] = 1;
	cout << recurse(0, 0) << endl;
}