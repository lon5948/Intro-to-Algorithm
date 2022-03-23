#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector< pair<int, int> > pandemic;
vector<int> ans;
void maxgame(int target, int num);

int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);

	int n, m, s, start, end, strength;
	vector<int> hold;
	vector<int>::iterator sit, eit;
	cin >> n >> m >> s;
	hold.resize(n);
	pandemic.resize(m);
	ans.resize(s + 1, 0);
	int num = n;

	for (int i = 0; i < n; i++) {
		cin >> hold[i];
	}

	sort(hold.begin(), hold.end());

	for (int i = 0; i < m; i++) {
		cin >> start >> end >> strength;
		sit = lower_bound(hold.begin(), hold.end(), start);
		eit = upper_bound(hold.begin(), hold.end(), end);
		pandemic[i].first = eit - sit;
		num -= eit - sit;
		pandemic[i].second = strength;
	}

	maxgame(s, num);
}

void maxgame(int target, int num) {

	for (int i = 0; i < pandemic.size(); i++) {
		int point = pandemic[i].first;
		int strength = pandemic[i].second;

		for (int j = target; j >= strength; j--) {
			ans[j] = max(ans[j], ans[j - strength] + point);
		}
	}

	cout << ans[target] + num;
}
