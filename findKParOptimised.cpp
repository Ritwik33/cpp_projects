#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define rep(i, a, b) for(int i = a;i<b;i++)

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
void dfs(int node, int par = 0) {
    parent[node][0] = par;

    rep(i, 1, 17) {
        if(!(parent[node][i] = parent[parent[node][i-1]][i-1])) break;
    }

    for(auto it:adj[node]) {
        if(it != par) dfs(it, node);
    }
}

int findKPar(int node, int k) {
    int cnt = 0;
    int kPar = node;
    while(k) {
        if(k&1) kPar = parent[kPar][cnt];
        cnt++;
        k = k>>1;
    }
    return kPar;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    inputTree();
    dfs(1);
    int q;
    cin >> q;    
    while(q--) {
        int node, k;
        cin >> node >> k;
        cout << findKPar(node, k) << "\n";
    }
    return 0;
}