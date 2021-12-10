#include<bits/stdc++.h>
using namespace std;
#define vi                                                         vector<int>
#define vi2                                                        vector<vector<int>>
#define rep(i, a, b)                                               for(int i = a;i<b;i++)
#define repd(i, a)                                                 for(int i = a;i>=0;i--)
#define setbits(x)                                                 __builtin_popcountll(x)
#define FIO                                                        ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

vi adj[2*100005];
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

int depth[2*100005];
void dfs(int node, int par, int& dia) {
    depth[node] = 0;
    int fmax = -1, smax = -1;
    vi largestDepths;
    for(auto child:adj[node]) {
        if(child == par) continue;
        dfs(child, node, dia);
        depth[node] = max(depth[node], 1 + depth[child]);
        largestDepths.push_back(depth[child]);
    }
    if(largestDepths.size() == 0) dia = max(dia, 0);
    else if(largestDepths.size() == 1) dia = max(dia, depth[node]);
    else {
        sort(largestDepths.begin(), largestDepths.end());
        dia = max(dia, 2 + largestDepths[largestDepths.size() - 1] + largestDepths[largestDepths.size() - 2]);
    }
}

int main() {
    FIO;
    inputTree();
    int dia = 0;
    dfs(1, 0, dia);
    cout << dia << "\n";
    return 0;
}