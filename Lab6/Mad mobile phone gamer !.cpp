#include<iostream>
#include<vector>
#include<queue>
#include <limits>
using namespace std;

int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);

	int inf = numeric_limits<int>::max();
	int n, m, k;
	cin >> n >> m;
	vector< vector<long long> > cost(n);

	for (int i = 0; i < n; i++) {
		cost[i].resize(n, inf);
		cost[i][i] = 0;
	}

	for (int i = 0; i < m; i++) {
		int a, b, w;
		cin >> a >> b >> w;
		if (a == b) {
			continue;
		}
		if (w < cost[a][b]) {
			cost[a][b] = w;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int p = 0; p < n; p++) {
				if (cost[j][i] + cost[i][p] < cost[j][p]) {
					cost[j][p] = cost[j][i] + cost[i][p];
				}
			}
		}
	}
	
	cin >> k;
	for (int i = 0; i < k; i++) {
		int f, t;
		cin >> f >> t;
		
		if (cost[f][t] < inf) {
			cout << cost[f][t] << '\n';
		}
		else {
			cout << -1 << '\n';
		}
	}
}
