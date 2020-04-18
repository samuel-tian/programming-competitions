/*input
3
rrr
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
#define maxn 100010
#define debug cout << "pass" << endl;
// #define bitSize 262144  /*smallest pow of 2 bigger than size of array */
// #define bitSize2 bitSize*2
using namespace std;
 
typedef pair<int, int> pii;
typedef vector<pii> vii;

int main(){
  	int n; cin >> n;
  	string necklace; cin >> necklace;
  	bool found = false;
  	int maxcount = 0;
  	for (int i = 0; i < n; i++){
    	char right = necklace[(i+1)%n];
    	char left = necklace[i];
    	if (right == 'r' || right == 'b' || left == 'r' || left == 'b'){
      		found = true;
      		int counter = 0;
      		int newright = (i+1)%n;
      		while (necklace[newright] == 'w'){
        		counter++;
        		newright = (newright+1)%n;
      		}
      		right = necklace[newright];
      		while (necklace[newright] == right || necklace[newright] == 'w'){
        		counter++;
        		newright = (newright + 1) % n;
        		if (counter >= n){
          			found = false;
          			break;
        		}
    		}
      		int newleft = i;
      		while (necklace[newleft] == 'w'){
        		counter++;
        		newleft = (newleft-1+n)%n;
      		}
      		left = necklace[newleft];
      		while (necklace[newleft] == left || necklace[newleft] == 'w'){
        		counter++;
        		newleft = (newleft - 1 + n) % n;
        		if (counter >= n){
          			found = false;
          			break;
        		}
      		}
      		maxcount = max(maxcount, counter);
      		if (maxcount >= n){
        		found = false;
        		break;
      		}
    	}
  	}
  	if (found == false) cout << n << endl;
  	else cout << maxcount << endl;
}