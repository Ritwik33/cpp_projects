#include<bits/stdc++.h>
using namespace std;
#define int                                                        long long
#define vi                                                         vector<int>
#define vvi                                                        vector<vector<int>>
#define pb(x)                                                      push_back(x)
#define ppb                                                        pop_back()
#define rep(i, a, b)                                               for(int i = a;i<b;i++)
#define repd(i, a)                                                 for(int i = a;i>=0;i--)
#define setbits(x)                                                 __builtin_popcountll(x)
#define FIO                                                        ios_base::sync_with_stdio(false); cin.tie(NULL);

class Solution {
private:
    bool isPossible(vector<int>& weights, int days, int capacity) {
        int cnt = 0;
        int time = 1;
        for(int i = 0;i<weights.size();i++) {
            cnt += weights[i];
            if(cnt > capacity) {
                cnt = weights[i];
                time++;
            }
        }
        return time <= days;
    }
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int maxWeight = *max_element(weights.begin(), weights.end());
        int sumOfWeights = accumulate(weights.begin(), weights.end(), 0);
        int low = maxWeight, high = sumOfWeights;
        while(low < high) {
            int capacity = low + (high - low)/2;
            if(isPossible(weights, days, capacity)) {
                high = capacity;
            } else {
                low = capacity + 1;
            }
        }
        return high;
    }
};

void solve() {
    Solution obj;
    int n;
    cin >> n;
    vi weights(n);
    for(auto &it:weights) cin >> it;
    int days;
    cin >> days;
    cout << obj.shipWithinDays(weights, days);
}

signed main() {
    FIO;
    solve();
    return 0;
}