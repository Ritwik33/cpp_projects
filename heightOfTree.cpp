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

int height = 0;
void dfs(int node, int par = -1, int level = 0) {
    height = max(height, level+1);
    for(auto it:adj[node]) {
        if(it != par) dfs(it, node, level+1);
    }
}


int main() {
    inputTree();
    dfs(1);
    cout << height << endl;
    return 0;
}