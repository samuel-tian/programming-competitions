//
// Created by samue on 12/22/2019.
//

#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pi;
typedef pair<pair<int, int>, int> pii;
typedef vector<int> vi;
typedef vector<pair<int, int> > vpi;

#define f first
#define s second
#define pb push_back
#define mp make_pair
#define endl '\n'

const int MAXN = 50005;
const int INF = INT_MAX;
const int MAXLOG = 21;
const int MAXSEG = (1<<18);

void setIO(string name) {
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (name == "input") {
        freopen("input.txt","r",stdin);
    }
    else {
        freopen((name+".in").c_str(),"r",stdin);
        freopen((name+".out").c_str(),"w",stdout);
    }
}

int n;
pair<int, int> points[MAXN];
pair<double, pair<int, int> > angles[MAXN];

double dist(pair<int, int> a, pair<int, int> b) {
    long long dx = a.first - b.first;
    long long dy = a.second - b.second;
    return dx*dx + dy*dy;
}

int ccw(pair<int, int> a, pair<int, int> b, pair<int, int> c) {
    return (b.f - a.f) * (c.s - a.s) - (b.s - a.s) * (c.f - a.f);
}

double convexHull() {
    vector<pair<int, int> > hull;
    int minIndex = -1;
    int minX = INF;
    for (int i = 0; i < n; ++i) {
        if (points[i].first < minX) {
            minX = points[i].first;
            minIndex = i;
        }
    }
    for (int i = 0; i < n; ++i) {
        int dx = points[i].first - points[minIndex].first;
        int dy = points[i].second - points[minIndex].second;
        if (dx == 0 && dy == 0) {
            angles[i] = make_pair(NINF, make_pair(points[i].first, points[i].second));
        }
        else {
            angles[i] = make_pair(atan2(dy, dx), make_pair(points[i].first, points[i].second));
        }
    }
    sort(angles, angles + n);
    for (int i = 0; i < n; ++i) {
        while (hull.size() >= 2 && ccw(hull[hull.size() - 1], hull[hull.size() - 2], angles[i].second) > 0) {
            hull.pop_back();
        }
        hull.push_back(angles[i].second);
    }
    double ret = 0;
    for (int i = 0; i < hull.size(); ++i) {
        ret += dist(hull[i], hull[(i + 1) % hull.size()]);
    }
    return ret;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >>
    }
}