#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);

	int t, n, m, s, x, y;
	cin >> t;
	for (int i = 0; i < t; i++) {
		vector< vector<int> > neighbor;
		vector<int> police;
		vector<int> hideout;
		vector<bool> visited;
		vector<int> mcost;
		vector<int> pcost;

		cin >> n >> m >> s;
		s = s - 1;
		mcost.resize(n, 1e5);
		pcost.resize(n, 1e5);
		neighbor.resize(n);

		for (int j = 0; j < m; j++) {
			int a, b;
			cin >> a >> b;
			a = a - 1;
			b = b - 1;
			neighbor[a].push_back(b);
			neighbor[b].push_back(a);
		}

		cin >> x;
		for (int j = 0; j < x; j++) {
			int inp;
			cin >> inp;
			inp = inp - 1;
			police.push_back(inp);
		}

		cin >> y;
		for (int j = 0; j < y; j++) {
			int inp;
			cin >> inp;
			inp = inp - 1;
			hideout.push_back(inp);
		}

		visited.resize(n, false);
		queue<int> q1;
		q1.push(s);
		mcost[s] = 0;
		while (!q1.empty()) {
			int f = q1.front();
			q1.pop();
			visited[f] = true;
			for (int j = 0; j < neighbor[f].size(); j++) {
				int nei = neighbor[f][j];
				if (!visited[nei] && mcost[f] + 1 < mcost[nei]) {
					mcost[nei] = mcost[f] + 1;
					q1.push(nei);
				}
			}
		}

		queue<int> q2;
		visited.clear();
		visited.resize(n, false);
		for (int j = 0; j < police.size(); j++) {
			int num = police[j];
			q2.push(num);
			pcost[num] = 0;
		}

		while (!q2.empty()) {
			int f = q2.front();
			visited[f] = true;
			q2.pop();
			for (int j = 0; j < neighbor[f].size(); j++) {
				int nei = neighbor[f][j];
				if (!visited[nei] && pcost[f] + 1 < pcost[nei]) {
					pcost[nei] = pcost[f] + 1;
					q2.push(nei);
				}
			}
		}

		for (int j = 0; j < hideout.size(); j++) {
			int hide = hideout[j];
			if (mcost[hide] < pcost[hide]) {
				cout << "Yes" << '\n';
				break;
			}
			else if (j == hideout.size() - 1 && mcost[hide] >= pcost[hide]) {
				cout << "No" << '\n';
			}
		}
	}
	return 0;
}
