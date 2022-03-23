#include <iostream>
#include <vector>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;

void LIS(vector<int>& seq, int n, vector<int>& node);
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);

    int n;
    cin >> n;
    vector<int> seq(n);
    vector<int> seq_rev(n);
    for (int i = 0; i < n; i++) {
        cin >> seq[i];
        seq_rev[i] = -seq[i];
    }

    vector<int> seq_node1(n);
    vector<int> seq_node2(n);
    vector<int> seqrev_node1(n);
    vector<int> seqrev_node2(n);
    LIS(seq, n, seq_node1);
    LIS(seq_rev, n, seqrev_node1);

    reverse(seq.begin(), seq.end());
    reverse(seq_rev.begin(), seq_rev.end());

    LIS(seq, n, seq_node2);
    LIS(seq_rev, n, seqrev_node2);

    int seq_max = 0, seqrev_max = 0;
    for (int i = 0; i < n; i++) {
        if (seq_node1[i] + seq_node2[n - i - 1] - 1 > seq_max) {
            seq_max = seq_node1[i] + seq_node2[n - i - 1] - 1;
        }
        if (seqrev_node1[i] + seqrev_node2[n - i - 1] - 1 > seqrev_max) {
            seqrev_max = seqrev_node1[i] + seqrev_node2[n - i - 1] - 1;
        }
    }
    cout << max(seq_max, seqrev_max);
    return 0;
}

void LIS(vector<int> &seq, int n,vector<int> &node) {
    vector<int> increase;
    increase.push_back(seq[0]);
    node[0] = 1;
    for (int i = 1; i < seq.size(); i++) {
        if (seq[i] <= increase[0]) {
            increase[0] = seq[i];
            node[i] = 1;
        }
        else if (seq[i] > increase[increase.size()-1]) {
            increase.push_back(seq[i]);
            node[i] = increase.size();
        }
        else {
            vector<int>::iterator it;
            it = lower_bound(increase.begin(), increase.end(),seq[i]);
            node[i] = it - increase.begin() + 1;
            increase[node[i] - 1] = seq[i];
        }
    }
}
