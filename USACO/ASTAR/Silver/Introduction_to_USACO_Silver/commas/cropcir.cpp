#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int n, xin, yin, rin;
    cin >> n;
    int xarray[n], yarray[n], rarray[n], carray[n];
    for (int input = 0; input < n; input++){
        cin >> xin >> yin >> rin;
        xarray[input] = xin;
        yarray[input] = yin;
        rarray[input] = rin;
        carray[input] = 0;
    }
    for (int cow = 0; cow < n; cow++){
        for (int other = 0; other <n; other++){
            if (cow != other){
                if (sqrt((xarray[cow]-xarray[other])*(xarray[cow]-xarray[other])+(yarray[cow]-yarray[other])*(yarray[cow]-yarray[other]))
                 <= rarray[cow] + rarray[other]){
                    carray[cow]++;
                }
            }
        }
    }
    for (int i = 0; i < n; i++) cout << carray[i] << endl;
}