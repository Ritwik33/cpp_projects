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

bool dfs(int node, int x, vi& path, int par = 0) {
    if(node == x) {
        path.push_back(node);
        return true;
    }
    path.push_back(node);
    for(auto it:adj[node]) {
        if(it != par) {
            if(dfs(it, x, path, node)) return true;
        }
    }
    path.pop_back();
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    inputTree();
    int node1, node2;
    cin >> node1 >> node2;
    vi path1;
    vi path2;
    dfs(1, node1, path1);
    dfs(1, node2, path2);
    int i = 0, j = 0, loc = -1;
    while(path1[i] == path2[j]) {
        loc++;
        i++;
        j++;
    }
    if(loc == min(path1.size(), path2.size()) - 1) loc--;
    int lca = path1[loc] = path2[loc];
    cout << lca << "\n";
    return 0;
}