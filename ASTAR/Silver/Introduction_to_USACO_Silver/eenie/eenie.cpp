#include <iostream>
#include <vector>
#define endl "\n"
using namespace std;

int main(){
  int n, l;
  cin >> n >> l;
  int input, eliminate[l];
  for (int i = 0; i < l; i++){
    cin >> input;
    eliminate[i] = input;
  }
  vector<int> cows;
  for (int k = 1; k <= n; k++){
    cows.push_back(k);
  }
  int length = n, current = 0;
  for (int turn = 0; turn < n - 1; turn++){
    int elim = eliminate[turn % l];
    current = (current + elim - 1) % length;
    cows.erase(cows.begin() + current);
    length--;
  }
  cout << cows[0] << endl;
}