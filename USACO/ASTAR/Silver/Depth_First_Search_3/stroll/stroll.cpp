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
// #define p 1000000007
#define eps 1e-9
#define maxn 100010
// #define bitSize 262144	/*smallest pow of 2 bigger than size of array */
// #define bitSize2 bitSize*2
using namespace std;
 
typedef pair<int, int> pii;
typedef vector<pii> vii;


pii points[1001];
int recurse(int current){
	int maxlength = 0;
	if (current==0) return 0;
	else{
		int length1 = 1, length2 = 1;
		length1 += recurse(points[current].f);
		length2 += recurse(points[current].s);
		return max(length1, length2);
	}
}
int main(){														 // USACO
	int p, input;
	cin >> p;
	for (int i = 1; i < p; i++){
		cin >> input;
		cin >> points[input].f >> points[input].s;
	}
	cout << recurse(1) << endl;
}