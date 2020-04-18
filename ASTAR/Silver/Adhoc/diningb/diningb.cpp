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
	int n; cin >> n;
	int dining[n]; for (int i = 0; i < n; i++) cin >> dining[i];
	int card1[n+1], card2[n+1];
	card1[0] = 0; card2[n] = 0;
	if (dining[0] == 1) card1[1] = 0;
	else card1[1] = 1;
	for (int i = 2; i <= n; i++){
		if (dining[i-1] == 1) card1[i] = card1[i-1];
		else card1[i] = card1[i-1]+1;
	}
	if (dining[n-1] == 1) card2[n-1] = 1;
	else card2[n-1] = 0;
	for (int i = n-2; i >= 0; i--){
		if (dining[i] == 2) card2[i] = card2[i+1];
		else card2[i] = card2[i+1] + 1;
	}
	/*for (int i = 0; i <= n; i++){
		cout << card1[i] << " ";
	}
	cout << endl;
	for (int i = 0; i <= n; i++){
		cout << card2[i] << " ";
	}
	cout << endl;*/
	int mincount = inf;
	for (int i = 0; i <= n; i++)
		mincount = min(mincount, card1[i] + card2[i]);
	cout << mincount << endl;
}