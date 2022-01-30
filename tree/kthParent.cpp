#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
#define rep(i, a, b) for(int i = a;i<b;i++)

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

int parent[100005];
void dfs(int node, int par = -1) {
    parent[node] = par;
    for(auto it:adj[node]) {
        if(it != par) dfs(it, node);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    inputTree();
    dfs(1);
    int q;
    cin >> q;
    while(q--) {
        int node, k, par;
        cin >> node >> k;
        par = node;
        while(k--) {
            par = parent[par];
        }
        cout << par << "\n";
    }
    return 0;
}