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

int visited[100005];
bool dfs(int source, int destination, vi& path) {
    visited[source] = true;
    path.push_back(source);
    if(source == destination) {
        for(auto it:path) cout << it << " ";
        cout << "\n";
        visited[source] = false;
        path.pop_back();
        return true;
    }
    for(auto it:adj[source]) {
        if(!visited[it]) {
            if(dfs(it, destination, path)) return true;
        }
    }
    visited[source] = false;
    path.pop_back();   
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    inputTree();
    int t;
    cin >> t;
    while(t--) {
        int source, destination;
        cin >> source >> destination;
        memset(visited, false, sizeof visited);
        vi path;
        dfs(source, destination, path);
    }
    return 0;
}