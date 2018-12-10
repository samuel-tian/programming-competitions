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
	int n;
	cin >> n;
	int cows[n];
	vector<int> modulo[7];
	for (int i = 0; i < n; i++){
		cin >> cows[i];
		cows[i] = cows[i] % 7;
	}
	int sum = 0;
	for (int i = 0; i < n; i++){
		sum = (sum + cows[i]) % 7;
		if (sum==0) sum = 7;
		modulo[sum - 1].push_back(i - 1);
	}
	int maxlength = 0;
	for (int i = 0; i < 7; i++){
		if (modulo[i].size() > 1){
			sort(modulo[i].begin(), modulo[i].end());
			int length = modulo[i][modulo[i].size() - 1] - modulo[i][0];
			if (length > maxlength) maxlength = length;
		}
	}
	cout << maxlength << endl;
}