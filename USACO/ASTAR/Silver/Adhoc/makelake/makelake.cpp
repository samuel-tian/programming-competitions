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

int main(){
	int r, c, e, n;
	cin >> r >> c >> e >> n;
	int lake[r][c];
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			cin >> lake[i][j];
	pair<pii, int> instr[n];
	for (int i = 0; i < n; i++)
		cin >> instr[i].f.f >> instr[i].f.s >> instr[i].s;
	for (int i = 0; i < n; i++){
		for (int dep = 0; dep < instr[i].s; dep++){
			int highest = 0;
			for (int row = instr[i].f.f - 1; row < instr[i].f.f + 2; row++)
				for (int col = instr[i].f.s - 1; col < instr[i].f.s + 2; col++)
					highest = max(highest, lake[row][col]);
			for (int row = instr[i].f.f - 1; row < instr[i].f.f + 2; row++)
				for (int col = instr[i].f.s - 1; col < instr[i].f.s + 2; col++)
					if (lake[row][col] == highest) lake[row][col]--;
		}
	}
	int depth = 0;
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			if (lake[i][j] < e)
				depth += (e - lake[i][j]);
	depth *= (72 * 72);
	cout << depth << endl;
}