#include <iostream>
using namespace std;

int main(){
    int N, count = 0;
    cin >> N;
    for (int B = 1; B <= 500; B++){
        for (int A = B; A <= 500; A++){
            if (A*A-B*B == N) count++;
        }
    }
    cout << count;
}