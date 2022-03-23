#include <iostream>
#include <queue>
#include <vector>
#include <map>
#include <math.h>
using namespace std;

vector< map<long long,long long> > cost;
vector<long long> parent;

bool bfs(long long s, long long t);
long long fordFulkerson(long long s, long long t);

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    long long f, n, m, c, t, k;
    cin >> f >> n >> m;

    long long total_node = f + 2*n + m + 3;
    parent.resize(total_node);
    cost.resize(total_node);

    for (long long i = 1; i <= f; i++) {
        cin >> cost[0][i];
    }

    for (long long i = 1; i <= n; i++) {
        cin >> cost[f + 2 * i - 1][f + 2 * i];
    }

    for (long long i = 1; i <= m; i++) {
        cin >> cost[f+2*n+i][total_node - 2];
    }

    cin >> c;
    map<long long,long long>::iterator it;
    for (long long i = 0; i < c; i++) {
        long long x, y, w;
        cin >> x >> y >> w;
        cost[x][f + 2 * y - 1] += w;
    }

    cin >> t;
    for (long long i = 0; i < t; i++) {
        long long x, y, w;
        cin >> x >> y >> w;
        cost[f + 2 * x][f + 2 * n + y] += w;
    }

    cin >> k;
    cost[total_node - 2][total_node - 1] = k;
    cout << fordFulkerson(0, total_node - 1);
    return 0;
}

bool bfs(long long s, long long t){
    
    vector<bool> visited(t + 1,false);

    queue<long long> q;
    q.push(s);
    visited[s] = true;
    parent[s] = -1;
    while (!q.empty()) {
        long long f = q.front();
        q.pop();
        
        map<long long, long long>::iterator neighbor_it;
        for (neighbor_it = cost[f].begin(); neighbor_it != cost[f].end(); neighbor_it++) {
            long long nei = neighbor_it->first;
            if (visited[nei] == false && cost[f][nei] > 0) {
                parent[nei] = f;
                if (nei == t) {
                    return true;
                }
                q.push(nei);
                visited[nei] = true;
            }
        }
    }
    return false;
}

long long fordFulkerson(long long s, long long t){

    long long maxflow = 0;

    while (bfs(s, t)) {
        long long flow = 1e15;

        for (long long v = t; v != s; v = parent[v]) {
            long long p = parent[v];
            flow = min(flow, cost[p][v]);
        }

        for (long long v = t; v != s; v = parent[v]) {
            long long p = parent[v];
            cost[p][v] -= flow;
            cost[v][p] += flow;
        }

        maxflow += flow;
    }
    return maxflow;
}
