/*input
219 800 4
934996703 15
988 698 539 71 990 334 225 888 592 385 656 479 98 736 160
432052274 41
333 625 340 95 840 344 129 110 315 347 909 670 402 616 9 451 154 79 440 839 656 328 431 392 983 261 841 70 772 114 105 90 323 551 929 666 32 390 730 651 2
203909483 88
11 285 771 441 725 609 448 404 391 839 738 3 679 808 775 144 790 879 234 464 781 514 482 164 904 814 894 554 815 728 171 177 13 293 970 89 901 417 844 644 608 581 646 638 740 420 782 882 650 367 345 431 880 826 946 783 991 191 688 158 919 210 334 283 502 655 371 755 72 214 398 146 395 316 238 449 119 246 695 993 544 829 983 734 869 140 652 78
925557826 87
932 832 656 686 903 221 435 933 719 829 601 956 995 49 74 811 864 240 408 910 232 951 738 567 685 958 58 688 388 883 974 319 67 981 356 969 554 142 254 272 970 854 227 317 652 127 469 891 534 378 123 485 468 689 521 425 746 208 812 533 130 47 514 837 367 978 620 338 300 825 916 616 431 742 899 457 275 277 931 111 744 619 631 168 717 191 980
*/
#include <iostream>
#include <utility>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

#define INF 9223372036854775807
#define endl '\n'
#define MAXC 100
#define ll long long

int a, b, n;
pair<ll, ll> dis[MAXC];
bool vis[MAXC];
ll adj[MAXC][MAXC];
priority_queue<pair<ll, ll> > pq;

void dijkstra(int start) {
	fill(dis, dis+MAXC, make_pair(INF, 0) );
	dis[start] = make_pair(0, 0);
	pq.push(make_pair(0, start));
	while (!pq.empty()) {
		int cur = pq.top().second;
		pq.pop();
		//cout << "cur" << " " << cur << endl;
		if (vis[cur]) continue;
		vis[cur] = true;

		for (int i = 0; i < MAXC; ++i) {
			if (adj[cur][i] == INF) continue;
			int nextCost = adj[cur][i];
			if (dis[cur].first + nextCost < dis[i].first) {
				dis[i].first = dis[cur].first + nextCost;
				dis[i].second = dis[cur].second + 1;
				pq.push(make_pair(-dis[i].first, i));
			}
		}
	}
}

int main() {
	for (int i = 0; i < MAXC; ++i) {
		fill(adj[i], adj[i] + MAXC, INF);
	}
	cin >> a >> b >> n;
	--a; --b;
	long long num, cost, one;
	for (int i = 0; i < n; ++i) {
		cin >> cost >> num;
		int nums[num];
		for (int j = 0; j < num; ++j) {
			cin >> nums[j];
			nums[j]--;
			//cout << nums[j] << " ";
		}
		//cout << endl;
		for (int x = 0; x < num; ++x) {
			for (int y = 0; y < num; ++y) {
				if (x == y) continue;
				adj[nums[x]][nums[y]] = min(adj[nums[x]][nums[y]], cost);
				adj[nums[y]][nums[x]] = min(adj[nums[y]][nums[x]], cost);
			}
		}
	}

	dijkstra(a);
	if (dis[b].first == INF) cout << -1 << " " << -1 << endl;
	else cout << dis[b].first << " " << dis[b].second + 1<< endl;;
}