#include<iostream>
#include<vector>
#include<queue>
#include<limits>
using namespace std;

int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);

	long long n, m;
	cin >> n >> m;

	long long inf = numeric_limits<long long>::max();

	vector<long long> cost(n + 1, inf);
	vector<long long> cost_rev(n + 1, inf);
	vector< pair<long long, long long> > edge;
	vector<long long> weight;
	cost[1] = 0;
	cost_rev[n] = 0;

	vector< vector< pair<long long, long long> > > neighbor(n + 1);
	vector< vector< pair<long long, long long> > > neighbor_rev(n + 1);
	for (long long i = 0; i < m; i++) {
		long long a, b, w;
		cin >> a >> b >> w;
		neighbor[a].push_back(make_pair(b, w));
		neighbor_rev[b].push_back(make_pair(a, w));
		edge.push_back(make_pair(a, b));
		weight.push_back(w);
	}

	vector<bool> visited(n + 1, false);
	priority_queue< pair<long long, long long>, vector< pair<long long, long long> >, greater< pair<long long, long long> > > pq;
	pq.push(make_pair(0, 1));
	while (!pq.empty()) {
		long long f = pq.top().second;
		visited[f] = true;
		pq.pop();

		for (long long i = 0; i < neighbor[f].size(); i++) {
			long long b = neighbor[f][i].first;
			long long w = neighbor[f][i].second;
			if (!visited[b] && cost[f] + w < cost[b]) {
				cost[b] = cost[f] + w;
				pq.push(make_pair(cost[b], b));
			}
		}
	}

	visited.clear();
	visited.resize(n + 1, false);
	priority_queue< pair<long long, long long>, vector< pair<long long, long long> >, greater< pair<long long, long long> > > pq1;
	pq1.push(make_pair(0, n));
	while (!pq1.empty()) {
		long long f = pq1.top().second;
		visited[f] = true;
		pq1.pop();

		for (long long i = 0; i < neighbor_rev[f].size(); i++) {
			long long a = neighbor_rev[f][i].first;
			long long w = neighbor_rev[f][i].second;

			if (!visited[a] && cost_rev[f] + w < cost_rev[a]) {
				cost_rev[a] = cost_rev[f] + w;
				pq1.push(make_pair(cost_rev[a], a));
			}
		}
	}

	long long sp = cost[n];
	for (long long i = 0; i < edge.size(); i++) {
		long long a = edge[i].first;
		long long b = edge[i].second;
		long long num = cost[a] + cost_rev[b] + weight[i] - sp;
		if (num > weight[i] || cost[a] == inf || cost_rev[b] == inf) {
			cout << -1 << '\n';
		}
		else {
			cout << num << '\n';
		}
	}
}
