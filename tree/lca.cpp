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

int parent[100005][17];
int level[100005];
void dfs(int node = 1, int par = 0, int lev = 1) {
    parent[node][0] = par;
    level[node] = lev;
    rep(i, 1, 17) {
        parent[node][i] = parent[parent[node][i-1]][i-1];
    }
    for(auto it:adj[node]) {
        if(it != par) dfs(it, node, lev+1);
    }
}

int findKPar(int node, int k) {
    int cnt = 0;
    int par = node;
    while(k) {
        if(k & 1) par = parent[par][cnt];
        cnt++;
        k = k>>1;
    }
    return par;
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
        cout << lca(u, v) << "\n";
    }
    return 0;
}