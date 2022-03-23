#include <iostream>
#include <vector>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;
vector< vector<int> > neighbor;
vector< vector<int> > neighbor_rev;
vector< vector<int> > new_nei;
vector<int> in;
vector<bool> visited;
vector<int> scc;
vector<int> cost;
vector<int> weight;
stack<int> s;
int num;

void dfs1(int node);
void dfs2(int node, int p);
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);

    int n, m;
    cin >> n >> m;
    neighbor.resize(n);
    neighbor_rev.resize(n);
    new_nei.resize(n);
    scc.resize(n);
    in.resize(n, 0);
    cost.resize(n);
    weight.resize(n);
    visited.resize(n, false);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        neighbor[a].push_back(b);
        neighbor_rev[b].push_back(a);
    }

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs1(i);
        }
    }

    visited.clear();
    visited.resize(n, false);

    int c = 0;
    while (!s.empty()) {
        int top = s.top();
        s.pop();
        if (!visited[top]) {
            num = 0;
            dfs2(top, c);
            c++;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < neighbor[i].size(); j++) {
            if (scc[i] != scc[neighbor[i][j]]) {
                new_nei[scc[i]].push_back(scc[neighbor[i][j]]);
                in[scc[neighbor[i][j]]]++;
            }
        }
    }

    queue<int> q;
    for (int i = 0; i < c; i++) {
        if (in[i] == 0) {
            q.push(i);
        }
    }
    while (!q.empty()) {
        int f = q.front();
        q.pop();
        for (int i = 0; i < new_nei[f].size(); i++) {
            if (cost[f] + weight[new_nei[f][i]] > cost[new_nei[f][i]]) {
                cost[new_nei[f][i]] = cost[f] + weight[new_nei[f][i]];
                q.push(new_nei[f][i]);
            }
        }
    }

    cout << *max_element(cost.begin(), cost.end());
    return 0;
}

void dfs1(int node) {
    visited[node] = true;
    for (int i = 0; i < neighbor[node].size(); i++) {
        int nei = neighbor[node][i];
        if (!visited[nei]) {
            dfs1(nei);
        }
    }
    s.push(node);
}

void dfs2(int node, int p) {
    num++;
    visited[node] = true;
    for (int i = 0; i < neighbor_rev[node].size(); i++) {
        int nei = neighbor_rev[node][i];
        if (!visited[nei]) {
            dfs2(nei, p);
        }
    }
    scc[node] = p;
    weight[p] = num;
    cost[p] = num;
}
