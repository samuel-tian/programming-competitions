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
#define maxn 1000
#define debug cout << "pass" << endl;
// #define bitSize 262144	/*smallest pow of 2 bigger than size of array */
// #define bitSize2 bitSize*2
using namespace std;
 
typedef pair<int, int> pii;
typedef vector<pii> vii;

int n, b;
pii gifts[maxn];
int compute_gifts(int coupon){
	pii copy[maxn] = gifts;
	copy[coupon] = mp(copy[coupon].f / 2, copy[coupon].s);
	int prices[maxn];
	for (int i = 0; i < n; i++)
		prices[i] = copy[i].f + copy[i].s;
	sort(prices, prices + n);
	int sum = 0; int counter = 0;
	while (sum + prices[counter] <= b){
		sum += prices[counter];
		counter++;
	}
	return counter;
}
int main(){
	cin >> n >> b;
	for (int i = 0; i < n; i++)
		cin >> gifts[i].f >> gifts[i].s;
	int maxgifts = 0;
	for (int i = 0; i < n; i++)
		maxgifts = max(maxgifts, compute_gifts(i));
	cout << maxgifts << endl;
}