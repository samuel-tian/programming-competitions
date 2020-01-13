//
// Created by samue on 10/8/2019.
//

/*
 * Graham scan for convex hull generation
 * --------------------------------------
 * 1) find the point with the least x coordinate
 * 2) calculate the angles to all of the other points with respect to the horizontal and sort the points by angle
 * 3) append points to the hull, until the appended point makes a concave angle with the previous two points
 * time complexity: O(n log n)
 */

#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define INF INT_MAX
#define NINF INT_MIN
#define MAXN 100000

int n;
pair<int, int> points[MAXN];
pair<double, pair<int, int> > angles[MAXN];

double dist(pair<int, int> a, pair<int, int> b) {
    long long dx = a.first - b.first;
    long long dy = a.second - b.second;
    return sqrt(dx*dx + dy*dy);
}

int ccw(pair<int, int> a, pair<int, int> b, pair<int, int> c) {

    return (b.first - a.first) * (c.second - a.second) - (b.second - a.second) * (c.first - a.first);
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
    }
    return ret;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> points[i].first >> points[i].second;
    }
    printf("%.2f\n", convexHull());
}