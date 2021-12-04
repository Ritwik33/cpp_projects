#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vi2 vector<vector<int>>
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

int deepest = 0;
int level[100005];
void dfs(int node, int par = 0, int lev = 1) {
    level[node] = lev;
    if(level[node] > level[deepest]) deepest = node;
    for(auto it:adj[node]) {
        if(it == par) continue;
        dfs(it, node, lev+1);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    inputTree();
    dfs(1);
    dfs(deepest);
    int dia = level[deepest] - 1;
    cout << dia << "\n";
    return 0;
}