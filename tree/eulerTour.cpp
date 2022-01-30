#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
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

int level[100005];
vi eulerTour;
void dfs(int node = 1, int par = 0, int lev = 1) {
    level[node] = lev;
    eulerTour.push_back(node);
    for(auto it:adj[node]) {
        if(it != par) {
            dfs(it, node, lev+1);
            eulerTour.push_back(node);
        }
    }
}

int firstOccurence[100005];
void formFirstOccurence() {
    memset(firstOccurence, -1, sizeof firstOccurence);
    rep(i, 0, eulerTour.size()) {
        if(firstOccurence[eulerTour[i]] == -1) firstOccurence[eulerTour[i]] = i;
    }
}

int lca(int u, int v) {
    int ind1, ind2;
    ind1 = firstOccurence[u];
    ind2 = firstOccurence[v];
    int highestNode = u;
    rep(i, ind1 + 1, ind2 + 1) {
        if(level[eulerTour[i]] < level[highestNode]) highestNode = eulerTour[i];
    }
    return highestNode;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    inputTree();
    dfs();
    formFirstOccurence();
    int q;
    cin >> q;
    while(q--) {
        int u, v;
        cin >> u >> v;
        cout << lca(u, v) << "\n";
    }
    return 0;
}