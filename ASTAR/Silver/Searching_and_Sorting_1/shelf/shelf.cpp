#include <iostream>
#include <algorithm>
using namespace std;

bool comp(int a, int c){
    return a > c;
}
int main(){
    int n, b, input;
    cin >> n >> b;
    int store[n];
    for (int i = 0; i < n; i++){
        cin >> input;
        store[i] = input;
    }
    sort(store, store + n, comp);
    int sum = 0, final;
    for (int counter = 0; counter < n; counter++){
        sum += store[counter];
        if (sum >= b){
            final = counter + 1;
            break;
        }
    }
    cout << final << endl;
}