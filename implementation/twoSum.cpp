#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vi2 vector<vector<int>>
#define rep(i, a, b) for(int i = a;i<b;i++)
#define repd(i, a) for(int i = a;i>=0;i--)

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    int nums[n];
    rep(i, 0, n) cin >> nums[i];
    int target;
    cin >> target;
    map<int, int> mpp;
    vi ans;
    rep(i, 0, n) {
        int diff = target - nums[i];
        if(mpp.find(diff) != mpp.end()) {
            ans.push_back(i);
            ans.push_back(mpp[diff]);
        }
        mpp[nums[i]] = i;
    }
    for(auto it:ans) cout << it << " ";
    return 0;
}