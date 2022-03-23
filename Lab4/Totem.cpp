#include<iostream>
#include<vector>
using namespace std;

int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);

	int num,MAX=0;
	cin >> num;
	vector<int> vec;
	vector<long long int> down;
	vector<long long int> up;
	vec.resize(num);
	for (int i = 0; i < num; i++) {
		cin >> vec[i];
		if (vec[i] > MAX) {
			MAX = vec[i];
		}
	}

	down.resize(MAX+1);
	up.resize(MAX+1);

	down[2] = 1;
	up[2] = 2;
	down[3] = 3;
	up[3] = 5;

	for (int i = 4; i <= MAX; i++) {
		down[i] = up[i - 2] + up[i - 1] + 1;
		if (down[i] > 1000000007) {
			down[i] %= 1000000007;
		}
		up[i] = down[i - 1] + down[i] + 1;
		if (up[i] > 1000000007) {
			up[i] %= 1000000007;
		}
	}

	for (int i = 0; i < num; i++) {
		if (vec[i] == 0) {
			cout << 0 << '\n';
		}
		else {
			if (4 * up[vec[i]] + 1 > 1000000007) {
				cout << (4 * up[vec[i]] + 1) % 1000000007 << '\n';
			}
			else {
				cout << 4 * up[vec[i]] + 1 << '\n';
			}
		}
	}

}
