#include <bits/stdc++.h>

using namespace std;

#define INF INT_MAX
#define endl '\n'
#define MAXN 100000

int n, m;
string newspaper;
string message;
vector<int> suffixArray;

vector<int> sortSuffixes(string message, int m) {
    vector<int> p(m), c(m); // permutation, equivalence class
    vector<pair<char, int> > s(m);
    for (int i = 0; i < m; ++i) {
        s[i] = make_pair(message[i], i);
    }
    sort(s.begin(), s.end());
    for (int i = 0; i < m; ++i) {
        p[i] = s[i].second;
    }
    int classes = 0;
    c[p[0]] = classes;
    for (int i = 1; i < m; ++i) {
        if (s[i].first != s[i - 1].first) {
            classes++;
        }
        c[p[i]] = classes;
    }
    for (int i = 0; i < ceil(log2(m)) + 1; ++i) {
        vector<pair<pair<int, int>, int> > t(m);
        for (int j = 0; j < m; ++j) {
            t[j] = make_pair(make_pair(c[j], c[(j + 1) % m]), j);
        }
        sort(t.begin(), t.end());
        for (int j = 0; j < m; ++j) {
            p[j] = t[j].second;
        }
        classes = 0;
        c[p[0]] = classes;
        for (int j = 1; j < m; ++j) {
            if (t[j].first != t[j - 1].first) {
                classes++;
            }
            c[p[j]] = classes;
        }
    }
    return p;
}

int main() {
//    freopen("input.txt", "r", stdin);
    cin >> n >> m;
    string in;
    while (n > 0) {
        cin >> in;
        n -= in.length();
        newspaper += in;
    }
    while (m > 0) {
        cin >> in;
        m -= in.length();
        message += in;
    }
    n = newspaper.length();
    m = message.length();

    int ret = 0;
    string concat = newspaper + message + "$";
    suffixArray = sortSuffixes(concat, concat.length());
    suffixArray.erase(suffixArray.begin());
    do {
        int longestMatch = 0;
        for (int i = 0; i < suffixArray.size(); ++i) {
            if (concat.substr(suffixArray[i]) == message + "$") {
                string sub = concat.substr(suffixArray[i]);
                if (i > 0) {
                    int j = 0;
                    string prevsub = concat.substr(suffixArray[i - 1]);
                    while (prevsub[j] == sub[j]) {
                        ++j;
                    }
                    longestMatch = j;
                }
                if (i < n-1) {
                    int j = 0;
                    string postsub = concat.substr(suffixArray[i + 1]);
                    while (postsub[j] == sub[j]) {
                        ++j;
                    }
                    longestMatch = max(longestMatch, j);
                }
                break;
            }
        }
        message = message.substr(longestMatch);
        ++ret;
        /*for (int i = 0; i < suffixArray.size(); ++i) {
            cout << suffixArray[i] << " ";
            for (int j = suffixArray[i]; j < concat.length(); ++j) {
                cout << concat[j];
            }
            cout << endl;
        }*/
    } while (message.length() > 0);
    cout << ret << endl;
    /*for (int i : suffixArray) {
        cout << i << " ";
    }
    cout << endl;*/

}