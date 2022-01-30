#include<bits/stdc++.h>
using namespace std;
#define int long long

int level[2*100005];
int subTreeSize[2*100005];
vector<int> adj[2*100005];

void dfs(int node, int par = -1, int lev = 0) {
    subTreeSize[node] = 1;
    level[node] = lev;
    for(auto it:adj[node]) {
        if(it != par) {
            dfs(it, node, lev + 1);
            subTreeSize[node] += subTreeSize[it];
        }
    }
}

void linova() {
    int n, k;
    cin >> n >> k;
    for(int i = 1;i<=n-1;i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1);
    priority_queue<int> pq;
    for(int i = 1;i<=n;i++) {
        pq.push(level[i] - (subTreeSize[i] - 1));
    }

    int ans = 0;
    while(k--) {
        ans += pq.top();
        pq.pop();
    }

    cout << ans << "\n";
}

signed main() {
    linova();
    return 0;
}