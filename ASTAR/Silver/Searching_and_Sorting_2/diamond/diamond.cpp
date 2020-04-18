/*input

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
#define inf 2000000000
#define p 1000000007
#define eps 1e-9
#define MAXN 50000
#define debug cout << "pass" << endl;
using namespace std;
typedef pair<int, int> pii;
typedef vector<pii> vii;

int n, k;
int diamonds[MAXN];
int temp1[MAXN+1], temp2[MAXN+1];
void increment(){
    int current = 0;
    for (int i = 0; i < n; i++){
        while (diamonds[i] - diamonds[current] > k && current+1 < n)
            current++;
        temp1[i+1] = i - current + 1;
        if (i != 0) temp1[i] = max(temp1[i], temp1[i-1]);
    }
}
void decrement(){
    int current = n-1;
    for (int i = n-1; i >= 0; i--){
        while (diamonds[current] - diamonds[i] > k && current-1 >= 0)
            current--;
        temp2[i] = current - i + 1;
        if (i != n-1) temp2[i] = max(temp2[i], temp2[i+1]);
    }
}
int main(){
    // freopen("diamond_cases\\10.out", "r", stdin); cin >> n; cout << n << endl; fclose(stdin);
    // freopen("diamond_cases\\10.in", "r", stdin);
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> diamonds[i];
    int maxshown = 0;
    sort(diamonds, diamonds + n);
    temp1[0] = 0; temp2[n] = 0;
    increment();
    decrement();
    int sumshow[MAXN+1];
    for (int i = 0; i <= n; i++){
        // cout << i sp temp1[i] sp temp2[i] << endl;
        sumshow[i] = temp1[i] + temp2[i];
    }
    cout << *max_element(sumshow, sumshow + n + 1) << endl;
    //fclose(stdin);
}