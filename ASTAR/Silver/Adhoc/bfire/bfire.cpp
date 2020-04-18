#include <bits/stdc++.h>  //includes everything, supported in CF, usaco, not POJ
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
// #define bitSize 262144  /*smallest pow of 2 bigger than size of array */
// #define bitSize2 bitSize*2
using namespace std;
 
typedef pair<int, int> pii;
typedef vector<pii> vii;

int main(){
  	int n; cin >> n;
  	int cows[n];
  	for (int i = 0; i < n; i++)
    	cows[i] = i+1;
  	int current = 0;
  	int tap = 1;
  	int ans;
  	cows[0] = 0;
  	while (cows[tap] == tap + 1){
    	/*for (int i = 0; i < n; i++)
    	  	cout << cows[i] << " ";
    	cout << '\t' << current + 1 sp tap + 1 << endl;*/
    	cows[tap] = current + 1;
    	current = tap;
    	tap = (2 * tap + 1) % n;
  	}
  	cout << current + 1 << endl;
}