#include<bits/stdc++.h>
using namespace std;

vector<int> adj[100005];
vector<int> path;

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

bool dfs(int node, int x, int par = -1) {
    if(node == x) {
        path.push_back(node);
        return true;
    }
    path.push_back(node);
    for(auto it:adj[node]) {
        if(it != par) {
            if(dfs(it, x, node)) return true;
        }
    }
    path.pop_back();
    return false;
}

void printPath() {
    int x;
    cin >> x;
    if(!dfs(1, x)) return;
    for(auto it:path) cout << it << " ";
}

int main() {
    inputTree();
    printPath();
    return 0;
}