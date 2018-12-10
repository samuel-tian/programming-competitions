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
using namespace std;
 
typedef pair<int, int> pii;
typedef vector<pii> vii;


int main(){
	//freopen("rand.txt", "r", stdin);
	string final = "";
	string temp;
	while (getline(cin, temp)){
		final += (temp + "\n");
	}
	/*for (int i = 0; i < 17; i++){
		cin >> temp;
		final += (temp+"\n");
	}*/
	//getline(cin, final);
	//cout << final << endl;
	int finalcount = 0;
	string maxstring = "";
	for (int i = 0; i < final.length(); i++){
		//if (final[i] == '\n') cout << "newline" sp i << endl;
		int next = i+1;
		if (final[i] == '\n') goto HERE;
		while ((final[next]<'A' || final[next]>'z') || (final[next] >'Z' && final[next] < 'a')){
			next++;
			if (next >= final.length()) break;
		}
		while (final[next] == '\n'){
			next++;
			if (next >= final.length()) break;
		}
		if (((final[i]>='A' && final[i] <= 'Z') || (final[i] >= 'a' && final[i] <= 'z')) && final[i]==final[next]){ // even palindromes
			int counter = 2;
			int leftpos = i-1;
			int rightpos = next+1;
			string pali;
			while (((final[leftpos]<'A' || final[leftpos]>'z') || (final[leftpos] >'Z' && final[leftpos] < 'a')) || final[leftpos] == '\n'){
				leftpos--;
				if (leftpos < 0) break;
			}
			while (((final[rightpos]<'A' || final[rightpos]>'z') || (final[rightpos] >'Z' && final[rightpos] < 'a')) || final[rightpos] == '\n'){
				rightpos++;
				if (rightpos >= final.length()) break;
			}
			if ((final[leftpos]<'A' || final[leftpos]>'z') || (final[rightpos]<'A' || final[rightpos]>'z') || final[rightpos] == '\n')
				goto HERE;
			while (tolower(final[leftpos])==tolower(final[rightpos])){
				counter += 2;
				pali = final.substr(leftpos, rightpos - leftpos + 1);
				leftpos--;
				rightpos++;
				while (((final[leftpos]<'A' || final[leftpos]>'z') || (final[leftpos] >'Z' && final[leftpos] < 'a')) || final[leftpos] == '\n'){
					leftpos--;
					if (leftpos < 0) break;
				}
				while (((final[rightpos]<'A' || final[rightpos]>'z') || (final[rightpos] >'Z' && final[rightpos] < 'a')) || final[rightpos] == '\n'){
					rightpos++;
					if (rightpos >= final.length()) break;
				}
			}
			if (counter > finalcount){
				maxstring = pali;
				finalcount = counter;
			}
		}
		if ((final[i]>='A' && final[i] <= 'Z') || (final[i] >= 'a' && final[i] <= 'z')){ // odd palindromes
			int counter = 1;
			int leftpos = i-1;
			int rightpos = i+1;
			string pali;
			while (((final[leftpos]<'A' || final[leftpos]>'z') || (final[leftpos] >'Z' && final[leftpos] < 'a')) || final[leftpos] == '\n'){
				leftpos--;
				if (leftpos < 0) break;
			}
			while (((final[rightpos]<'A' || final[rightpos]>'z') || (final[rightpos] >'Z' && final[rightpos] < 'a')) || final[rightpos] == '\n'){
				rightpos++;
				if (rightpos >= final.length()) break;
			}
			if ((final[leftpos]<'A' || final[leftpos]>'z') || (final[rightpos]<'A' || final[rightpos]>'z'))
				goto HERE;
			while (tolower(final[leftpos])==tolower(final[rightpos])){
				counter += 2;
				pali = final.substr(leftpos, rightpos - leftpos + 1);
				leftpos--;
				rightpos++;
				while (((final[leftpos]<'A' || final[leftpos]>'z') || (final[leftpos] >'Z' && final[leftpos] < 'a')) || final[leftpos] == '\n'){
					leftpos--;
					if (leftpos < 0) break;
				}
				while (((final[rightpos]<'A' || final[rightpos]>'z') || (final[rightpos] >'Z' && final[rightpos] < 'a')) || final[rightpos] == '\n'){
					rightpos++;
					if (rightpos >= final.length()) break;
				}
			}
			if (counter > finalcount){
				maxstring = pali;
				finalcount = counter;
			}
		}
		HERE:;
	}
	cout << finalcount << endl;
	cout << maxstring << endl;
}