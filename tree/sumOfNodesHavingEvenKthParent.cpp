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

int parent[100005][17];
void dfs(int node = 1, int par = 0) {
    parent[node][0] = par;
    rep(i, 1, 17) {
        if(!(parent[node][i] = parent[parent[node][i-1]][i-1])) break;
    }
    for(auto it:adj[node]) {
        if(it != par) {
            dfs(it, node);
        }
    }
}

int findkthParent(int node, int k) {
    int cnt = 0;
    while(k) {
        if(k & 1) node = parent[node][cnt];
        cnt++;
        k >>= 1;
    }
    return node;
}

int sumOfNodesHavingEvenKthParent(int k, int node = 1, int par = 0) {
    int cnt = 0;
    for(auto it:adj[node]) {
        if(it != par) {
            cnt += sumOfNodesHavingEvenKthParent(k, it, node);
        }
    }
    int kthParent = findkthParent(node, k);
    if((kthParent != 0) && (kthParent % 2 == 0)) cnt++;
    return cnt;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    inputTree();
    dfs();
    int k;
    cin >> k;
    cout << sumOfNodesHavingEvenKthParent(k);
    return 0;
}