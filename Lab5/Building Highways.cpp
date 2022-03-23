#include<iostream>
#include<vector>
#include<map>
using namespace std;

vector<int> parent;
int find(int x);

int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);

	int t, n, m, k, f, s;
	cin >> t;

	for (int i = 0; i < t; i++) {
		cin >> n >> m >> k >> f >> s;
		
		bool out = true;

		parent.resize(n);
		for (int j = 0;j < n; j++) {
			parent[j] = j;
		}

		vector< pair<int, int> > slow_road;
		vector< pair<int, int> > fast_road;
		for (int j = 0; j < m; j++) {
			int a, b, weight;
			char type;
			cin >> a >> b >> type;
			if (type == 'F') {
				weight = f;
				fast_road.push_back(make_pair(a, b));
			}
			else if (type == 'S') {
				weight = s;
				slow_road.push_back(make_pair(a, b));
			}
		}

		int smax = 0,smin=0,fmax=0,fmin=0;
		for (int j = 0; j < slow_road.size(); j++) {
			int a = slow_road[j].first;
			int b = slow_road[j].second;
			
			if (find(a) == find(b)) {
				continue;
			}
			else {
				parent[find(a)] = find(b);
				smax++;
			}
		}
		fmin = n - 1 - smax;

		for (int j = 0; j < fast_road.size(); j++) {
			int a = fast_road[j].first;
			int b = fast_road[j].second;
			if (find(a) == find(b)) {
				continue;
			}
			else {
				parent[find(a)] = find(b);
			}
		}

		int p = find(0);
		for (int j = 1; j < n; j++) {
			if (find(j) != p) {
				out = false;
				break;
			}
		}

		if (!out) {
			cout << "No" << '\n';
			continue;
		}

		for (int j = 0; j < n; j++) {
			parent[j] = j;
		}

		for (int j = 0; j < fast_road.size(); j++) {
			int a = fast_road[j].first;
			int b = fast_road[j].second;
			if (find(a)==find(b)) {
				continue;
			}
			else {
				parent[find(a)] = find(b);
				fmax++;
			}
		}
		smin = n - 1 - fmax;

		if (f != s) {
			if ((k - n * s + s) % (f - s) == 0) {
				int x = (k - n * s + s) / (f - s);
				int y = n - 1 - x;
				if (x >= fmin && x <= fmax && y >= smin && y <= smax) {
					out = true;
				}
				else {
					out = false;
				}
			}
			else {
				out = false;
			}
		}
		else {
			if (k == (n-1)*f) {
				out = true;
			}
			else {
				out = false;
			}
		} 
		

		if (out) {
			cout << "Yes" << '\n';
		}
		else {
			cout << "No" << '\n';
		}
	}
}

int find(int x) {
	while (x != parent[x]) {
		parent[x] = parent[parent[x]];
		x = parent[x];
	}
	return x;
}
