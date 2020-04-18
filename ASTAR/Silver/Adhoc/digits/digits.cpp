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
// #define bitSize 262144	/*smallest power of 2 bigger than size of array */
// #define bitSize2 bitSize*2
using namespace std;
 
typedef pair<int, int> pii;
typedef vector<pii> vii;

int convert(int base, int num[50]){
	int sum = 0;
	for (int i = 0; i < 50; i++){
		sum += (num[i] * pow(base, 49-i));
	}
	return sum;
}
int base2[50], base3[50]; 
int main(){
	string temp2, temp3; cin >> temp2 >> temp3;
	int size2 = temp2.length(), size3 = temp3.length();
	reverse(temp2.begin(), temp2.end());
	reverse(temp3.begin(), temp3.end());
	for (int i = 0; i < size2; i++)
		base2[49-i] = temp2[i] - '0';
	for (int i = 0; i < size3; i++)
		base3[49-i] = temp3[i] - '0';
	for (int i = 49; i >= 50 - size2; i--){
		for (int j = 49; j >= 50 - size3; j--){
			int original2 = 0;
			if (base2[i] == 0) base2[i] = 1;
			else{
				base2[i] = 0;
				original2 = 1;
			}
			// cout << convert(2, base2) << endl;
			int original3 = 0;
			if (base3[j] == 0){
				base3[j] = 1;
				if (convert(2, base2) == convert(3, base3)){
					cout << convert(2, base2) << endl;
					goto HERE;
				}
				base3[j] = 2;
				if (convert(2, base2) == convert(3, base3)){
					cout << convert(2, base2) << endl;
					goto HERE;
				}
			}
			else if (base3[j] == 1){
				original3 = 1;
				base3[j] = 0;
				if (convert(2, base2) == convert(3, base3)){
					cout << convert(2, base2) << endl;
					goto HERE;
				}
				base3[j] = 2;
				if (convert(2, base2) == convert(3, base3)){
					cout << convert(2, base2) << endl;
					goto HERE;
				}
			}
			else{
				original3 = 2;
				base3[j] = 1;
				if (convert(2, base2) == convert(3, base3)){
					cout << convert(2, base2) << endl;
					goto HERE;
				}
				base3[j] = 0;
				if (convert(2, base2) == convert(3, base3)){
					cout << convert(2, base2) << endl;
					goto HERE;
				}
			}
			base2[i] = original2;
			base3[j] = original3;
		}
	}
	HERE:;
}