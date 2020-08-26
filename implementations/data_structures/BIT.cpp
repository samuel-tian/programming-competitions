#include <bits/stdc++.h>

using namespace std;

template<typename T>
struct BIT {
    int n;
    vector<T> arr;
    BIT() = default;
    BIT(int n) {
        resize(n);
    }
    void resize(int n) {
        this->n = n;
        arr.resize(n+1);
    }
    void clear() {
        this->n = 0;
        arr.clear();
    }
	void update(int i, T v) {
        i++;
		while (i <= n) {
			arr[i] = arr[i] + v;
			i += i & (-i);
		}
	}
	T get(int i) {
		T ret = 0;
        i++;
		while (i > 0) {
			ret = ret + arr[i];
			i -= i & (-i);
		}
		return ret;
	}
	T query(int i, int j) {
        return get(j) - get(i-1);
    }
};

int main() {
    
}
