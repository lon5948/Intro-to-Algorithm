#include <iostream>
#include <vector>
using namespace std;
typedef long long int lon;

int main() {
	int n, t;
	lon num;
	cin >> n >> t;

	vector<vector<lon>> vec;
	vec.resize(t);

	for (int i = 0; i < t; i++) {
		for (int j = 0; j < n; j++) {
			cin >> num;
			vec[i].push_back(num);
		}
	}

	for (int i = t-2; i >= 0; i--) {
		for (int j = 0; j < n; j++) {
			if (n == 1) {
				vec[i][j] += vec[i + 1][j];
			}
			else if (j == 0) {
				if (vec[i+1][j] > vec[i + 1][j+1]) {
					vec[i][j] += vec[i + 1][j];
				}
				else {
					vec[i][j] += vec[i + 1][j+1];
				}
			}
			else if(j == n-1){
				if (vec[i + 1][j] > vec[i + 1][j - 1]) {
					vec[i][j] += vec[i + 1][j];
				}
				else {
					vec[i][j] += vec[i + 1][j - 1];
				}
			}
			else {
				if (vec[i + 1][j] > vec[i + 1][j - 1] && vec[i + 1][j] > vec[i + 1][j + 1]) {
					vec[i][j] += vec[i + 1][j];
				}
				else if (vec[i + 1][j - 1] > vec[i + 1][j + 1]) {
					vec[i][j] += vec[i + 1][j - 1];
				}
				else {
					vec[i][j] += vec[i + 1][j + 1];
				}
			}
		}
	}

	for (int i = 0; i < n; i++) {
		cout << vec[0][i] << " ";
	}
}
