#include<bits/stdc++.h>
using namespace std;
#define vi                                                         vector<int>
#define vi2                                                        vector<vector<int>>
#define rep(i, a, b)                                               for(int i = a;i<b;i++)
#define repd(i, a)                                                 for(int i = a;i>=0;i--)
#define setbits(x)                                                 __builtin_popcountll(x)
#define FIO                                                        ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

int main() {
    FIO;
    int n;
    cin >> n;
    vi vec(n);
    rep(i, 0, n) cin >> vec[i];
    do {
        for(auto it:vec) cout << it << " ";
        cout << "\n";
    } while(next_permutation(vec.begin(), vec.end()));
    return 0;
}