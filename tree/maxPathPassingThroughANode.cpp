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
void inputTree(int numOfNodes) {
    rep(i, 1, numOfNodes) {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
}

int in[2*100005];
int parent[2*100005];
void dfsIn(int node = 1, int par = 0) {
    in[node] = 0;
    parent[node] = par;
    for(auto child:adj[node]) {
        if(child == par) continue;
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

void dfsComputeSumOfLargestTwoDepths(int& sumOfLargestTwoDepthsBeneathNode, int node, int par) {
    vi depthsOfChildren;
    for(auto child:adj[node]) {
        if(child == par) continue;
        dfsComputeSumOfLargestTwoDepths(sumOfLargestTwoDepthsBeneathNode, child, node);
        depthsOfChildren.pb(in[child]);
    }
    int sizeOfDepthsOfChildren = depthsOfChildren.size();
    if(sizeOfDepthsOfChildren == 0) sumOfLargestTwoDepthsBeneathNode = max(sumOfLargestTwoDepthsBeneathNode, 0);
    else if(sizeOfDepthsOfChildren == 1) sumOfLargestTwoDepthsBeneathNode = max(sumOfLargestTwoDepthsBeneathNode, in[node]);
    else {
        sort(depthsOfChildren.begin(), depthsOfChildren.end());
        int lastIndex = sizeOfDepthsOfChildren - 1;
        int secondLastIndex = sizeOfDepthsOfChildren - 2;
        int largestDepth = depthsOfChildren[lastIndex];
        int secondLargestDepth = depthsOfChildren[secondLastIndex];
        sumOfLargestTwoDepthsBeneathNode =   max(sumOfLargestTwoDepthsBeneathNode, 2 + largestDepth + secondLargestDepth);
    }
}

int maxDepthBeneathNode[2*100005];
void dfsComputeMaxDepthBeneathNode(int node = 1, int par = 0) {
    maxDepthBeneathNode[node] = -1;
    for(auto child:adj[node]) {
        if(child == par) continue;
        dfsComputeMaxDepthBeneathNode(child, node);
        if(in[child] > maxDepthBeneathNode[node]) maxDepthBeneathNode[node] = in[child];
    }
}

void solve() {
    int numOfNodes;
    cin >> numOfNodes;
    inputTree(numOfNodes);
    dfsIn();
    dfsOut();
    dfsComputeMaxDepthBeneathNode();
    rep(i, 1, numOfNodes + 1) {
        int sumOfLargestTwoDepthsBeneathNode = 0;
        dfsComputeSumOfLargestTwoDepths(sumOfLargestTwoDepthsBeneathNode, i, parent[i]);
        cout << max(sumOfLargestTwoDepthsBeneathNode, 1 + maxDepthBeneathNode[i] + out[i]) << " ";
    }
}

int main() {
    FIO;
    solve();
    return 0;
}