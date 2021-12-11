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

int in[2*100005];
void dfsIn(int node = 1, int parent = 0) {
    in[node] = 0;
    for(auto child:adj[node]) {
        if(child == parent) continue;
        dfsIn(child, node);
        in[node] = max(in[node], 1 + in[child]);
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
    if(parent != 0) {
        out[node] = 1 + max(deepestExceptNode, out[parent]);
    }
    for(auto child:adj[node]) {
        if(child == parent) continue;
        dfsOut(child, node, parent);
    }
}

int ans[2*100005];
void dfsComputeAns(int node = 1, int parent = 0) {
    int maxi = -1;
    ans[node] = out[node];
    for(auto child:adj[node]) {
        if(child == parent) continue;
        dfsComputeAns(child, node);
        if(in[child] > maxi) maxi = in[child];
    }
    ans[node] = max(ans[node], 1 + maxi);
}

void solve() {
    int numOfNodes;
    cin >> numOfNodes;
    inputTree(numOfNodes);
    dfsIn();
    dfsOut();
    dfsComputeAns();
    rep(i, 1, numOfNodes+1) cout << ans[i] << " ";
}

int main() {
    FIO;
    solve();
    return 0;
}