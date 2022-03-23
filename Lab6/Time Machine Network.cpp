#include<iostream>
#include<vector>
#include<queue>
#include <algorithm>
using namespace std;

vector<long long> cost;
vector<long long> index;
vector< pair< pair<long long, long long>, long long > > edge;

bool negcycle(long long mid, long long n);
int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);

	long long n, m;
	cin >> n >> m;

	for (long long i = 0; i < m; i++) {
		long long a, b, w;
		cin >> a >> b >> w;
		edge.push_back(make_pair(make_pair(a, b),w));
		if (w < 0) {
			index.push_back(w);
		}
	}
	sort(index.begin(), index.end());
	
	if (!negcycle(0,n)) {
		cout << "GO AHEAD";
	}
	else if (negcycle(index.size() - 1, n)) {
		cout << "NO WAY BACK";
	}
	else {
		long long left = 0;
		long long right = index.size() - 1;
		long long mid;
		while (right - left > 1) {
			mid = (left + right) / 2;
			if (negcycle(mid, n)) {
				left = mid;
			}
			else {
				right = mid;
			}
		}
		cout << index[left];
	}
}

bool negcycle(long long mid,long long n) {
	cost.clear();
	cost.resize(n, 1e9);
	cost[0] = 0;

	for (long long i = 0; i < n - 1; i++) {
		for (long long j = 0; j < edge.size(); j++) {
			long long weight = edge[j].second;
			long long a = edge[j].first.first;
			long long b = edge[j].first.second;
			if (cost[a] + weight < cost[b] && weight >= index[mid]) {
				cost[b] = cost[a] + weight;
			}
		}
	}

	for (long long j = 0; j < edge.size(); j++) {
		long long weight = edge[j].second;
		long long a = edge[j].first.first;
		long long b = edge[j].first.second;
		if (cost[a] + weight < cost[b] && weight >= index[mid]) {
			return true;
		}
	}
	return false;
}
