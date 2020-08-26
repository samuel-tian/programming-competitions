#include <bits/stdc++.h>

using namespace std;

template<typename T>
struct BIT {
    int n;
    vector<T> arr1, arr2;
    BIT() = default;
    BIT(int n) {
        resize(n);
    }
    void resize(int n) {
        this->n = n;
        arr1.resize(n+1);
        arr2.resize(n+1);
    }
    void clear() {
        this->n = 0;
        arr1.clear();
        arr2.clear();
    }
	void update_util(vector<T>& arr, int i, T v) {
        i++;
		while (i <= n) {
			arr[i] = arr[i] + v;
			i += i & (-i);
		}
	}
    void update(int i, int j, T v) {
        update_util(arr1, i, v);
        update_util(arr1, j+1, -v);
        update_util(arr2, i, -v*(i-1));
        update_util(arr2, j+1, v*j);
    }
	T get_util(vector<T>& arr, int i) {
		T ret = 0;
        i++;
		while (i > 0) {
			ret = ret + arr[i];
			i -= i & (-i);
		}
		return ret;
	}
    T get(int i) {
        return get_util(arr1, i) * i + get_util(arr2, i);
    }
	T query(int i, int j) {
        return get(j) - get(i-1);
    }
};

int main() {

}
