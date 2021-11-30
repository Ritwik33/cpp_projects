#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define rep(i, a, b) for(int i = a;i<b;i++)
#define repd(i, a) for(int i = a;i>=0;i--)

vi adj[100005];
void inputTree() {
    int n;
    cin >> n;
    rep(i, 1, n) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}

int level[100005];
int parent[100005][17];
void dfs(int node = 1, int par = 0, int lev = 1) {
    level[node] = lev;
    parent[node][0] = par;
    rep(i, 1, 17) {
        if(!(parent[node][i] = parent[parent[node][i-1]][i-1])) break;
    }
    for(auto it:adj[node]) {
        if(it != par) dfs(it, node, lev+1);
    }
}

int findKPar(int node, int k) {
    int cnt = 0;
    while(k) {
        if(k & 1) node = parent[node][cnt];
        cnt++;
        k = k>>1;
    }
    return node;
}

int lca(int u, int v) {
    if(level[v] < level[u]) swap(u, v);
    int k = level[v] - level[u];
    v = findKPar(v, k);
    if(u == v) return u = v;
    repd(i, 16) {
        if(parent[u][i] != parent[v][i]) {
            u = parent[u][i];
            v = parent[v][i];
        }
    }
    return parent[u][0] = parent[v][0];
}

int dist(int u, int v) {
    return level[u] + level[v] - 2*level[lca(u, v)];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    inputTree();
    dfs();
    int q;
    cin >> q;
    while(q--) {
        int u, v;
        cin >> u >> v;
        cout << dist(u, v) << "\n";
    }
    return 0;
}