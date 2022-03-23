#include<iostream>
#include<vector>
#include<map>
#include<queue>
using namespace std;

vector< map<long long, long long> > cost;
vector<long long> parent;

bool bfs(long long s, long long t);
long long fordFulkerson(long long s, long long t);
int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);

	long long n, m;
	cin >> n;
	long long total_node = n + 2;
	cost.resize(total_node);
	parent.resize(total_node);

	for (long long i = 1;i <= n;i++) {
		cin >> cost[0][i];
	}

	for (long long i = 1; i <= n; i++) {
		cin >> cost[i][total_node-1];
	}

	cin >> m;
	for (long long i = 0; i < m; i++) {
		long long a, b, w;
		cin >> a >> b >> w;
		cost[a][b] += w;
		cost[b][a] += w;
	}

	cout << fordFulkerson(0,total_node-1);
	return 0;
}

bool bfs(long long s, long long t) {
	vector<bool> visited(t + 1, false);
	queue<long long> q;
	q.push(s);
	visited[s] = true;

	while (!q.empty()) {
		long long f = q.front();
		q.pop();

		map<long long, long long>::iterator it;
		for (it = cost[f].begin(); it != cost[f].end(); it++) {
			long long neighbor = it->first;
			if (visited[neighbor] == false && cost[f][neighbor] > 0) {
				parent[neighbor] = f;
				if (neighbor == t) {
					return true;
				}
				q.push(neighbor);
				visited[neighbor] = true;
			}
		}
	}
	return false;
}

long long fordFulkerson(long long s, long long t) {
	long long max_flow = 0;

	while (bfs(s,t)) {
		long long flow = 1e9;
		for (long long v = t; v != s; v = parent[v]) {
			long long p = parent[v];
			flow = min(flow, cost[p][v]);
		}

		for (long long v = t; v != s; v = parent[v]) {
			long long p = parent[v];
			cost[p][v] -= flow;
			cost[v][p] += flow;
		}
		max_flow += flow;
	}

	return max_flow;
}
