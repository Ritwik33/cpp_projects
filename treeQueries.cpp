#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define rep(i, a, b) for(int i = a;i<b;i++)
#define repd(i, a) for(int i = a;i>=0;i--)

vi adj[2*100005];
void inputTree(int n) {
    rep(i, 1, n) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}

int parent[2*100005][18];
int level[2*100005];
void dfs(int node = 1, int par = 0, int lev = 1) {
    parent[node][0] = par;
    level[node] = lev;
    rep(i, 1, 18) {
        if(!(parent[node][i] = parent[parent[node][i-1]][i-1])) break;
    }
    for(auto it:adj[node]) {
        if(it != par) dfs(it, node, lev+1);
    }
}

int findKthPar(int node, int k) {
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
    v = findKthPar(v, k);
    if(u == v) return u = v;
    repd(i, 17) {
        if(parent[u][i] != parent[v][i]) {
            u = parent[u][i];
            v = parent[v][i];
        }
    }
    return parent[u][0] = parent[v][0];
}

bool isPossible(vi& vertices, int deepest) {
    for(auto it:vertices) {
        if(level[it] - level[lca(it, deepest)] > 1) return false;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    inputTree(n);
    dfs();
    while(m--) {
        int numOfVertices;
        cin >> numOfVertices;
        vi vertices(numOfVertices);
        int deepest = 0;
        rep(i, 0, numOfVertices) {
            cin >> vertices[i];
            if(level[vertices[i]] > level[deepest]) {
                deepest = vertices[i];
            }
        }
        if(isPossible(vertices, deepest)) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}