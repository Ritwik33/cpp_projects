#include<bits/stdc++.h>
using namespace std;
//#define int                                                        long long
#define vi                                                         vector<int>
#define vvi                                                        vector<vector<int>>
#define pb(x)                                                      push_back(x)
#define ppb                                                        pop_back()
#define rep(i, a, b)                                               for(int i = a;i<b;i++)
#define repd(i, a)                                                 for(int i = a;i>=0;i--)
#define setbits(x)                                                 __builtin_popcountll(x)
#define FIO                                                        ios_base::sync_with_stdio(false); cin.tie(NULL);

vi adj[2*100005];
void inputTree(int n) {
    rep(i, 1, n) {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
}

int in[2*100005];
int maxInPath[2*100005];
int maxDepthBeneathNode[2*100005];
void dfsIn(int node = 1, int par = 0) {
    in[node] = 0;
    maxDepthBeneathNode[node] = -1;
    vi depthsOfChildren;
    for(auto child:adj[node]) {
        if(child == par) continue;
        dfsIn(child, node);
        in[node] = max(in[node], 1 + in[child]);
        maxDepthBeneathNode[node] = max(maxDepthBeneathNode[node], in[child]);
        depthsOfChildren.pb(in[child]);
    }
    int len = depthsOfChildren.size();
    if(len == 0) maxInPath[node] = max(maxInPath[node], 0);
    else if(len == 1) maxInPath[node] = max(maxInPath[node], in[node]);
    else {
        sort(depthsOfChildren.begin(), depthsOfChildren.end());
        int lastIndex = len - 1;
        int secondLastIndex = len - 2;
        int highestDepth = depthsOfChildren[lastIndex];
        int secondHighestDepth = depthsOfChildren[secondLastIndex];
        maxInPath[node] = max(maxInPath[node], 2 + highestDepth + secondHighestDepth);
    }
}

int out[2*100005];
void dfsOut(int node = 1, int parent = 0, int grandParent = 0) {
    out[node] = 0;
    int deepestExceptNode = 0;
    for(auto child:adj[parent]) {
        if(child == node || child == grandParent) continue;
        deepestExceptNode = max(deepestExceptNode, 1 + in[child]);
    }
    if(parent != 0) out[node] = 1 + max(deepestExceptNode, out[parent]);
    for(auto child:adj[node]) {
        if(child == parent) continue;
        dfsOut(child, node, parent);
    }
}

void solve() {
    int n;
    cin >> n;
    inputTree(n);
    dfsIn();
    dfsOut();
    rep(node, 1, n) {
        cout << max(maxInPath[node], 1 + maxDepthBeneathNode[node] + out[node]) << " ";
    }
}

int main() {
    FIO;
    solve();
    return 0;
}