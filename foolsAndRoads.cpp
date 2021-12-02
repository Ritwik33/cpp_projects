#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define rep(i, a, b) for(int i = a;i<b;i++)
#define repd(i, a) for(int i = a;i>=0;i--)

vi adj[100005];
map<pair<int, int>, int> roadNo;
void inputTree(int n) {
    rep(i, 1, n) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        roadNo[{u, v}] = i;
        roadNo[{v, u}] = i;
    }
}

int parent[100005][17];
int level[100005];
void dfs(int node = 1, int par = 0, int lev = 1) {
    parent[node][0]  = par;
    level[node] = lev;
    rep(i, 1, 17) {
        if(!(parent[node][i] = parent[parent[node][i-1]][i-1])) break;
    }
    for(auto it:adj[node]) {
        if(it != par) dfs(it, node, lev+1);
    }
}

int findkthParent(int node, int k) {
    int cnt = 0;
    while(k) {
        if(k & 1) node = parent[node][cnt];
        cnt++;
        k = k>>1;
    }
    return node;
}

int contribution[100005];
int lca(int u, int v) {
    if(level[v] < level[u]) swap(u, v);
    int k = level[v] - level[u];
    v = findkthParent(v, k);
    if(u == v) return u = v;
    repd(i, 16) {
        if(parent[u][i] != parent[v][i]) {
            u = parent[u][i];
            v = parent[v][i];
        }
    }
    return parent[u][0] = parent[v][0];
}

int ans[100005];
void dfsAdd(int node = 1, int par = 0) {
    for(auto it:adj[node]) {
        if(it != par) {
            dfsAdd(it, node);
            contribution[node] += contribution[it];
        }
    }
    if(par != 0) {
        ans[roadNo[{node, par}]] = contribution[node];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    inputTree(n);
    dfs();
    int k;
    cin >> k;
    while(k--) {
        int u, v;
        cin >> u >> v;
        contribution[u] += 1;
        contribution[v] += 1;
        contribution[lca(u, v)] -= 2;
    }
    dfsAdd();
    rep(i, 1, n) cout << ans[i] << " ";
    return 0;
}