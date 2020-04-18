/*input
1500 100 4
250 25
150 9
120 5
200 8
*/
#include <iostream>
#include <algorithm>
#include <vector>
#define endl "\n"
using namespace std;
struct Part{
    float force, mass, tag;
};
bool comp(Part a, Part b){
    return a.force/a.mass > b.force/b.mass;
}
int main(){
    float m, f;
    int n, length;
    vector<int> output;
    cin >> f >> m >> n;
    Part parts[n];
    float maxacc = f / m, acc;
    for (int i = 0; i < n; i++){
        cin >> parts[i].force >> parts[i].mass;
        parts[i].tag = i + 1;
    }
    sort(parts, parts + n, comp);
    for (int j = 0; j <= n; j++){
        m += parts[j].mass;
        f += parts[j].force;
        acc = f/m;
        if (acc <= maxacc){
                length = j;
            for (int k = 0; k < j; k++){
                output.push_back(parts[k].tag);
            }
            break;
        }
        else{
            maxacc = acc;
        }
    }
    sort(output.begin(), output.end());
    for (int w = 0; w < length; w++){
        cout << output[w] << endl;
    }
    if (length == 0) cout << "NONE" << endl;
}