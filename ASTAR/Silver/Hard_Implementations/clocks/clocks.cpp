/*input
9 9 12
6 6 6
6 3 6
*/
#include <bits/stdc++.h>
#define DEBUG
#define f first
#define s second
#define pb push_back
#define ll long long
#define mp make_pair
#define endl '\n'
#define sp << ' ' <<
#define inf 9223372036854775807
#define p 1000000007
#define eps 1e-9
#define MAXN 100010
#define debug cout << "pass" << endl;
using namespace std;
typedef pair<int, int> pii;
typedef vector<pii> vii;

string minseq = "111222333444555666777888999";
int position[9];
bool comp(string a, string b){
	if (a.length() > b.length()) return true;
	else if (a.length() < b.length()) return false;
	else{
		for (int i = 0; i < a.length(); i++){
			if (a[i] > b[i]) return true;
			else if (a[i] < b[i]) return false;
		}
	}
	return true;
}
bool check(int clocks[9]){
	string moves[9] = {"1245", "123", "2356", "147", "24568", "369", "4578", "789", "5689"};
	int pcopy[9]; memcpy(pcopy, position, sizeof(pcopy));
	for (int i = 0; i < 9; i++){
		for (int j = 0; j < clocks[i]; j++){
			for (int k = 0; k < moves[i].length(); k++){
				pcopy[moves[i][k]-'1'] = (pcopy[moves[i][k]-'1'] + 3) % 12;
			}
		}
	}
	for (int i = 0; i < 9; i++)
		if (pcopy[i] != 0) return false;
	return true;
}
void recurse(int current, string seq, int clocks[9]){
	if (comp(seq, minseq)) return;
	if (check(clocks)){
		minseq = seq;
	}
	if (current == 9) return;
	for (int i = 0; i < 4; i++){
		string temp = seq;
		for (int ni = 0; ni < i; ni++){
			temp += to_string(current+1);
		}
		int copy[9]; memcpy(copy, clocks, sizeof(copy));
		copy[current] = i;
		recurse(current + 1, temp, copy);
		
	}
	return;
}
int main(){
	for (int i = 0; i < 9; i++){
		cin >> position[i];
		position[i] = position[i] % 12;
	}
	int temp[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
	recurse(0, "", temp);
	for (int i = 0; i < minseq.length(); i++){
		if (i==0) cout << minseq[0];
		else cout << " " << minseq[i];
	}
	cout << endl;
}