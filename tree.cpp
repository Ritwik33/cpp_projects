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


void dfs(int node, int par = -1) {
    cout << node << " ";
    for(auto it:adj[node]) {
        if(it != par) dfs(it, node);
    }
 }

 void bfs(int root) {
     queue<pair<int,int>> q;
     q.push({root, -1});
     while(!q.empty()) {
        int node = q.front().first;
        int par = q.front().second;
        q.pop();
        cout << node << " ";
        for(auto it:adj[node]) {
            if(it != par) q.push({it, node});
        }
     }
 }

int main() {
    return 0;
}