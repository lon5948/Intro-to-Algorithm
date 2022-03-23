#include <iostream>
#include <vector>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;

vector<long long> coin;
vector<long long> dp;
vector<long long> change;
long long leastcoin(long long target);
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);

    int n, q;
    cin >> n;
    coin.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> coin[i];
    }

    cin >> q;
    change.resize(q);
    long long MAX = 0;
    for (int i = 0; i < q; i++) {
        long long money, m;
        cin >> money;
        for (int j = 0; j < n; j++) {
            cin >> m;
            money -= m * coin[j];
        }
        if (-money > MAX) {
            MAX = -money;
        }
        change[i] = -money;
    }

    dp.resize(MAX + 1, -1);

    for (int i = 0; i < q; i++) {
        if (change[i] == 0) {
            cout << 0 << '\n';
        }
        else {
            cout << leastcoin(change[i]) << '\n';
        }
    }
    return 0;
}

long long leastcoin(long long target) {

    if (target == 0) {
        return 0;
    }
    else if (target == 1) {
        return 1;
    }
    else if (dp[target] != -1) {
        return dp[target];
    }

    long long least = 1e18;
    for (int i = 0; i < coin.size(); i++) {
        if (coin[i] > target) {
            continue;
        }
        else {
            if (leastcoin(target - coin[i]) + 1 < least) {
                least = leastcoin(target - coin[i]) + 1;
            }
        }
    }
    dp[target] = least;
    return least;
}
