#include <iostream>
#include <string>
using namespace std;

int main(){
	int n;
	char l;
	cin >> n >> l;
	int counter, current = 1;
	string currentcopy;
	while (counter < n){
		currentcopy = to_string(current);
		bool possible = true;
		for (int i = 0; i < currentcopy.length(); i++){
			if (currentcopy[i]==l){
				possible = false;
				break;
			}
		}
		if (possible == true){
			counter++;
			current++;
		}
		else{
			current++;
		}
	}
	
	cout << current-1 << endl;
}