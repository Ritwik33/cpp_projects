#include<bits/stdc++.h>
using namespace std;
#define vi                                                         vector<int>
#define vi2                                                        vector<vector<int>>
#define rep(i, a, b)                                               for(int i = a;i<b;i++)
#define repd(i, a)                                                 for(int i = a;i>=0;i--)
#define setbits(x)                                                 __builtin_popcountll(x)
#define FIO                                                        ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

vi adj[2*100005];
void inputTree(int numOfNodes) {
    rep(i, 1, numOfNodes) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}

int depth[2*100005];
void dfs(int& diameter, int node = 1, int parent = 0) {
    depth[node] = 0;
    vi largestDepths;
    for(auto child:adj[node]) {
        if(child == parent) continue;
        dfs(diameter, child, node);
        depth[node] = max(depth[node], 1 + depth[child]);
        largestDepths.push_back(depth[child]);
    }
    int lenOfLargestDepths = largestDepths.size();
    if(lenOfLargestDepths == 0) diameter = max(diameter, 0);
    else if(lenOfLargestDepths == 1) diameter = max(diameter, depth[node]);
    else {
        sort(largestDepths.begin(), largestDepths.end());
        int lastIndex = lenOfLargestDepths - 1;
        int secondLastIndex = lenOfLargestDepths - 2;
        int highestDepth = largestDepths[lastIndex];
        int secondHighestDepth = largestDepths[secondLastIndex];
        diameter = max(diameter, 2 + highestDepth + secondHighestDepth);
    } 
}

void solve() {
    int numOfNodes;
    cin >> numOfNodes;
    inputTree(numOfNodes);
    int diameter = 0;
    dfs(diameter);
    cout << diameter << "\n";
}

int main() {
    FIO;
    solve();
    return 0;
}