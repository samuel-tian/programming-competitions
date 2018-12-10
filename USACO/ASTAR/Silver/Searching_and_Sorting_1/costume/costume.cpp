#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int n, s;
    cin >> n >> s;
    int lengths[n], count = 0, input;
    for (int i = 0; i < n; i++){
        cin >> input;
        lengths[i] = input;
    }
    for (int cow1 = 0; cow1 < n - 1; cow1++){
        for (int cow2 = cow1 + 1; cow2 < n; cow2++){
            if (lengths[cow1] + lengths[cow2] <= s) count++;
        }
    }
    cout << count << endl;
}