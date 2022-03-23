#include<iostream>
#include<vector>
#include<map>
#include<math.h>
using namespace std;
typedef long long in;

vector<in> parent;
vector<in> node;
vector< vector< pair<in, in> > > neighbor;
vector<in> weight;

in find(in x);
in traversal(in n, in p);

int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);

	int n, m,count=0;
	cin >> n >> m;

	neighbor.resize(n + 1);
	weight.resize(n + 1,0);
	node.resize(n + 1);
	parent.resize(n + 1);
	for (int i = 1; i <= n; i++) {
		parent[i] = i;
	}

	multimap< in, pair<in, in> > edge;
	for (int i = 0; i < m; i++) {
		in a, b, c;
		cin >> a >> b >> c;
		edge.insert( make_pair(c,make_pair(a, b)));
	}

	multimap< in, pair<in, in> >::iterator it;
	in path = 0;
	for (it = edge.begin(); it != edge.end(); it++) {
		in w = it->first;
		in a = it->second.first;
		in b = it->second.second;
		if (find(a) != find(b)) {
			neighbor[a].push_back(make_pair(b, w));
			neighbor[b].push_back(make_pair(a, w));
			path += w;
			count++;
			if (path >= 1000000007) {
				path %= 1000000007;
			}
			parent[find(a)] = find(b);
		}
	}
	if (count < n - 1) {
		cout << -1;
		return 0;
	}

	traversal(1, 0);

	in num = 0;
	for (int i = 2; i <= n; i++) {
		num += weight[i] * node[i] * (n - node[i]);
		if (num >= 1000000007) {
			num %= 1000000007;
		}
	}

	cout << 2*path % 1000000007 << " " << 2*num % 1000000007;
	return 0;
}

in find(in x) {
	int num = x;
	while (num != parent[num]) {
		num = parent[num];
	}
	parent[x] = num;
	return num;
}

in traversal(in n, in p) {
	in num = 0;
	for (int i = 0; i < neighbor[n].size(); i++) {
		if (neighbor[n][i].first == p) {
			weight[n] = neighbor[n][i].second;
			if (neighbor[n].size() == 1) {
				node[n] = 1;
				return 1;
			}
		}
		else {
			num += traversal(neighbor[n][i].first, n);
			if (num >= 1000000007) {
				num %= 1000000007;
			}
		}
	}
	node[n] = num + 1;
	return num + 1;
}
