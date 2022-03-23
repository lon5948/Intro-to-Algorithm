#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <stack>
using namespace std;

vector<int> v;
int find(int x);

int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);

	int n, m, q;

	cin >> n >> m >> q;
	v.resize(n);
	map< pair<int, int>,bool > neighbor;
	vector< pair<int,int> > A;
	vector< pair<int, int> > U;
	stack<string> s;

	for (int i= 0;i<n;i++) {
		v[i] = i;
	}

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		neighbor[make_pair(a,b)] = false;
	}

	for (int i = 0; i < q; i++) {
		char ch;
		int a, b;
		cin >> ch >> a >> b;
		if (ch == 'A') {
			A.push_back(make_pair(a, b));
		}
		else if (ch == 'U') {
			A.push_back(make_pair(-1, -1));
			U.push_back(make_pair(a, b));
			map< pair<int, int>, bool >::iterator it1, it2;
			it1 = neighbor.find(make_pair(a, b));
			if (it1 != neighbor.end()) {
				neighbor[make_pair(a, b)] = true;
			}
			it2 = neighbor.find(make_pair(b, a));
			if (it2 != neighbor.end()) {
				neighbor[make_pair(b, a)] = true;
			}
		}
	}

	map< pair<int, int>,bool >::iterator it;
	for (it = neighbor.begin(); it!=neighbor.end(); it++) {
		int a, b;
		if (it->second == false) {
			a = it->first.first;
			b = it->first.second;
			if (find(a) == find(b)) {
				continue;
			}
			else if (v[a] == a) {
				v[a] = b;
			}
			else if (v[b] == b) {
				v[b] = a;
			}
			else {
				v[find(a)] = find(b);
			}
		}
	}

	for (int i = q-1,j=U.size()-1; i >=0; i--) {
		int a, b;
		if (A[i] == make_pair(-1, -1)) {
			a = U[j].first;
			b = U[j].second;
			j--;
			if (find(a) == find(b)) {
				continue;
			}
			else if (v[a] == a) {
				v[a] = b;
			}
			else if(v[b] == b){
				v[b] = a;
			}
			else {
				v[find(a)] = find(b);
			}
		}
		else {
			a = A[i].first;
			b = A[i].second;
			if (find(a) == find(b)) {
				s.push("YES");
			}
			else {
				s.push("NO");
			}
		}
	}
	int size = s.size();
	for (int i = 0; i < size; i++) {
		cout << s.top() << '\n';
		s.pop();
	}
}

int find(int x) {
	while (x != v[x]) {
		x = v[x];
	}
	return x;
}
