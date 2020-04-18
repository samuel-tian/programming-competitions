/*input

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
#define maxn 20
#define test cout << "pass" << endl;
// #define bitSize 262144  /*smallest pow of 2 bigger than size of array */
// #define bitSize2 bitSize*2
using namespace std;
 
typedef pair<int, int> pii;
typedef vector<pii> vii;

int n, bales[maxn], smallest = inf;
vector<int> maxbarn;
int counter = 0;
void recurse(int current, int barn1, int barn2, int barn3){
	counter++;
	if (current == n){
		int maxelement = max(max(barn1, barn2), barn3);
		//cout << maxelement sp barns[0] sp barns[1] sp barns[2] << endl;
		smallest = min(smallest, maxelement);
		return;
	}
	
	if (current == 0){
		recurse(3, bales[0]+bales[1]+bales[2], 0, 0);
		recurse(3, bales[0]+bales[1], bales[2], 0);
		recurse(3, bales[0]+bales[2], bales[1], 0);
		recurse(3, bales[0], bales[1], bales[2]);
	}
	else if (current == n-2){
    	if (barn1 >= barn2 && barn1 >= barn3){
    	    recurse(n, barn1, barn2+bales[current], barn3+bales[current+1]);
       		recurse(n, barn1, barn2+bales[current+1], barn3+bales[current]);
    	}
    	else if (barn2 >= barn1 && barn2 >= barn3){
       		recurse(n, barn1+bales[current], barn2, barn3+bales[current+1]);
       		recurse(n, barn1+bales[current+1], barn2, barn3+bales[current]);
    	}
    	else{
       		recurse(n, barn1+bales[current], barn2+bales[current+1], barn3);
       		recurse(n, barn1+bales[current+1], barn2+bales[current], barn3);
    	}
	}
	else{
		recurse(current+1, barn1+bales[current], barn2, barn3);
		recurse(current+1, barn1, barn2+bales[current], barn3);
		recurse(current+1, barn1, barn2, barn3+bales[current]);
	}
	
	return;
}
int main(){
	cin >> n;
	for (int i = 0; i < n; i++) cin >> bales[i];
	recurse(0, 0, 0, 0);
	cout << counter << endl;
	cout << smallest << endl;
}