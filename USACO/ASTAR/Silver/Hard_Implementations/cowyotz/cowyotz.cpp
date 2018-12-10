#include <bits/stdc++.h>
#define f first
#define s second
#define pb push_back
#define ll long long
#define mp make_pair
#define endl '\n'
#define sp << ' ' <<
#define inf 2000000000
#define MAXN 20
#define MAXE 20
#define MAXS 8
using namespace std;
typedef pair<int, int> pii;
typedef vector<pii> vii;

int n, s, e;
int expression[MAXE][MAXS];
int dice[MAXN], sides[MAXS+1];
int recurse(int pos){
	int counter = 0;
	if (pos == n){
		
		for (int i = 0; i < e; i++){
			for (int j = 0; j < s; j++){
				if (expression[i][j] > sides[j]) break;
				if (j == s-1){
					/*for (int k = 0; k < s; k++)
						cout << sides[k] << " ";
					cout << endl;*/
					return 1;
				}
			}
		}
		return 0;
	}
	for (int i = 0; i < s; i++){
		dice[pos] = i+1;
		sides[i]++;
		counter += recurse(pos+1);
		sides[i]--;
	}
	return counter;
}
int main(){
	//freopen("cowyotz_cases\\cowyotz.10.out", "r", stdin); cin >> n; cout << n << endl; fclose(stdin);
	//freopen("cowyotz_cases\\cowyotz.10.in", "r", stdin);
	cin >> n >> s >> e;
	for (int i = 0; i < e; i++){
		string temp; cin >> temp; //cout << temp << endl;
		int current = 0;
		while (current < temp.length()){
			while (temp[current] != '+' && current < temp.length()){
				int sum = 0;
				while (temp[current] != 'x'){
					sum = sum*10 + (temp[current] - '0');
					current++;
				}
				current++;
				//cout << "i" sp i sp "temp" sp temp[current] sp sum << endl;
				expression[i][temp[current]-'0'-1] = sum;
				//cout << i sp temp[current]-'0'-1 sp "checking" sp expression[i][temp[current]-'0'-1] << endl;
				current++;
			}
			current++;
		}
	}
	/*for (int i = 0; i < e; i++){
		for (int j = 0; j < s; j++){
			cout << expression[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;*/
	cout << recurse(0) << endl;
	//fclose(stdin);
}