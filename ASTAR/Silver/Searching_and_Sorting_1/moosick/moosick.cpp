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
	int n, c, input; 
	cin >> n;
	int song[n];
	for (int i = 0; i < n; i++){
		cin >> input;
		song[i] = input;
	}
	cin >> c;
	int chord[c];
	for (int i = 0; i < c; i++){
		cin >> input;
		chord[i] = input;
	}
	sort(chord, chord + c);
	int part[c];
	int count = 0;
	vector<int> found;
	for (int i = 0; i <= n - c; i++){
			copy(song + i, song + i + c, part);
			sort(part, part + c);
			for (int k = -88; k <= 88; k++){
				bool same = true;
				for (int r = 0; r < c; r++){
					part[r] += k;
					if (part[r]!=chord[r]) same = false;
					part[r] -= k;
				}
				if (same == true){
					count++;
					found.pb(i);
				}
		}
	}
	cout << count << endl;
	for (int i = 0; i < found.size(); i++){
		cout << found[i] + 1<< endl;
	}
}