/*input
6 3
2
1
1
3
2
1
1 6
3 3
2 4
*/
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
#define maxn 100001
#define debug cout << "pass" << endl;
// #define bitSize 262144  /*smallest pow of 2 bigger than size of array */
// #define bitSize2 bitSize*2
using namespace std;
 
typedef pair<int, int> pii;
typedef vector<pii> vii;

struct Breed{
	int a, b, c;
};
int main(){
	int n, q; cin >> n >> q;
	Breed cows[maxn] = {0, 0, 0};
	cows[0] = {0, 0, 0};
	for (int i = 1; i <= n; i++){
    	int temp; cin >> temp;
    	if (temp == 1){
      		cows[i] = cows[i-1];
      		cows[i].a++;
    	}
    	else if (temp == 2){
      		cows[i] = cows[i-1];
      		cows[i].b++;
    	}
    	else if (temp == 3){
      		cows[i] = cows[i-1];
      		cows[i].c++;
    	}
  	}
  	int queue1, queue2;
	for (int i = 0; i < q; i++){
		cin >> queue1 >> queue2;
		cout << cows[queue2].a-cows[queue1-1].a sp cows[queue2].b-cows[queue1-1].b sp cows[queue2].c-cows[queue1-1].c << endl;
	}
}