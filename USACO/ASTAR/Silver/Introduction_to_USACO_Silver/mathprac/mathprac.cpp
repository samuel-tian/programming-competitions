#include <iostream>
using namespace std;

int main(){
    int a, b, var = 0;
    cin >> a >> b;
    int first = 0, power10 = 1, power2 = 1;

    for (int e = a + 1; e <= 62; e++){
        for (int i = 1; i <= e; i++){
            power2 *= 2;
            if (e > 29 && power2 > 1000000000){
                power2 /= 10;
            }
        }
        while (power2 / power10 >= 10){
            power10 *= 10;
        }
        first = power2 / power10;
        if (first == b){
            var = e;
            break;
        }
        power2 = 1;
    }
    cout << var << endl;
}
