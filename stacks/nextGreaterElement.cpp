#include<bits/stdc++.h>
using namespace std;
#define vi                                                         vector<int>
#define vi2                                                        vector<vector<int>>
#define rep(i, a, b)                                               for(int i = a;i<b;i++)
#define repd(i, a)                                                 for(int i = a;i>=0;i--)
#define setbits(x)                                                 __builtin_popcountll(x)
#define int                                                        long long
#define FIO                                                        ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

signed main() {
    FIO;
    int n;
    cin >> n;
    int arr[n];
    rep(i, 0, n) cin >> arr[i];
    stack<int> stk;
    stk.push(arr[0]);
    rep(i, 1, n) {
        while(!stk.empty() && stk.top() < arr[i]) {
            cout << stk.top() << " -> " << arr[i] << "\n";
            stk.pop();
        }
        stk.push(arr[i]);
    }
    while(!stk.empty()) {
        cout << stk.top() << " -> " << -1 << "\n";
        stk.pop();
    }
    return 0;
}