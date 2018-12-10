#include <iostream>
using namespace std;

int main(){
    int n, counter = 0;
    cin >> n;
    while (n != 1){
        if (n % 2 == 0){
            n /= 2;
            counter += 1;
        }
        else{
            n = 3*n + 1;
            counter += 1;
        }
    }
    cout << counter << endl;
}