#include<bits/stdc++.h>
using namespace std;
#define vi                                                         vector<int>
#define vi2                                                        vector<vector<int>>
#define rep(i, a, b)                                               for(int i = a;i<b;i++)
#define repd(i, a)                                                 for(int i = a;i>=0;i--)
#define setbits(x)                                                 __builtin_popcountll(x)
#define FIO                                                        ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

vi adj[2*100005];
void inputTree(int n) {
    rep(i, 1, n) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}

int depth[2*100005];
void dfs(int node, int par) {
    depth[node] = 0;
    for(auto child:adj[node]) {
        if(child == par) continue;
        dfs(child, node);
        depth[node] = max(depth[node], 1 + depth[child]);
    }
}

int main() {
    FIO;
    int n;
    cin >> n;
    inputTree(n);
    rep(i, 1, n+1) {
        dfs(i, 0);
        cout << depth[i] << " ";
    }
    return 0;
}