#include <bits/stdc++.h>	//includes everything, supported in CF, usaco, not POJ
#define DEBUG
#define f first
#define s second
#define pb push_back
#define ll long long
#define mp make_pairs
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

int n, weights[20], maxcows = 0;
bool carry(int a, int b){
	bool carry = 0;
	while (a>0 && b>0){
		if (a%10 + b%10 >= 10) return false;
	}
	return true;
}
void recurse(int x, int num, int sum){
	maxcows = max(maxcows, num);
	if (x>=n) return;
	if (carry(weights[x], sum)==true) recurse(x + 1, num + 1, sum + weights[x]);
	recurse(x+1, num, sum);
}
int main(){
	cin >> n;
	for (int i = 0; i < n; i++) cin >> weights[i];
	recurse(0, 0, 0);
	cout << maxcows << endl;
}