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

int dp[100005][2];
void dfs(int node = 1, int par = 0) {
    dp[node][0] = 0;
    dp[node][1] = 0;
    for(auto it:adj[node]) {
        if(it == par) continue;
        dfs(it, node);
    }
    if(adj[node].size() == 1) return;
    for(auto it:adj[node]) {
        if(it == par) continue;
        dp[node][0] += max(dp[it][0], dp[it][1]);
    }
    for(auto picked:adj[node]) {
        if(picked == par) continue;
        int sum = 1 + dp[picked][0] + (dp[node][0] - max(dp[picked][0], dp[picked][1]));
        dp[node][1] = max(dp[node][1], sum);
    }
}

void solve() {
    cout << max(dp[1][0], dp[1][1]) << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    inputTree();
    dfs();
    solve();
    return 0;
}