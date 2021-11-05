#include<bits/stdc++.h>
using namespace std;

vector<int> adj[100005];
void inputTree() {
    int n;
    cin >> n;
    for(int i = 1;i<=n-1;i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}

int subTreeSize[100005];
void dfs(int node, int par = -1) {
    subTreeSize[node] = 1;
    for(auto it:adj[node]) {
        if(it != par) {
            dfs(it, node);
            subTreeSize[node] += subTreeSize[it];
        }
    }
}

int main() {
    inputTree();
    dfs(1);
    int q;
    cin >> q;
    while(q--) {
        int x;
        cin >> x;
        cout << subTreeSize[x] << endl;
    }
    return 0;
}