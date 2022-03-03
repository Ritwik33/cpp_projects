//https://practice.geeksforgeeks.org/problems/help-the-old-man3848/1

#include<bits/stdc++.h>
using namespace std;

#define endl                                                       '\n'
#define inf                                                        1e18
#define mod                                                        1000000007
#define int                                                        long long
#define vi                                                         vector<int>
#define pii                                                        pair<int, int>
#define ff                                                         first
#define ss                                                         second
#define mii                                                        map<int, int>
#define umii                                                       unordered_map<int, int>
#define mp 														   make_pair
#define vvi                                                        vector<vector<int>>
#define pb(x)                                                      push_back(x)
#define ppb                                                        pop_back()
#define rep(i, a, b)                                               for(int i = a;i<b;i++)
#define repd(i, a)                                                 for(int i = a;i>=0;i--)
#define setbits(x)                                                 __builtin_popcountll(x)
#define ps(x, y)                                                   fixed << setprecision(y) << x
#define w(q)                                                       int q; cin >> q; while(q--)
#define FIO                                                        ios_base::sync_with_stdio(false); cin.tie(NULL)

class Solution {
public:
	int cnt = 0;
	void toh(int src, int dest, int helper, int N, int n, vector<int>& ans) {
		if (!N) return;
		toh(src, helper, dest, N - 1, n, ans);
		cnt++;
		if (cnt == n) {
			ans.push_back(src), ans.push_back(dest);
			return;
		}
		toh(helper, dest, src, N - 1, n, ans);
	}
	vector<int> shiftPile(int N, int n) {
		// code here
		vector<int> ans;
		toh(1, 3, 2, N, n, ans);
		return ans;
	}
};

void solve() {
	int N, n; cin >> N >> n;
	Solution obj;
	vector<int> ans = obj.shiftPile(N, n);
	cout << ans[0] << ' ' << ans[1] << endl;
}

int32_t main() {
	FIO;

// #ifndef ONLINE_JUDGE
// 	freopen("input.txt", "r", stdin);
// 	freopen("output.txt", "w", stdout);
// #endif

	int t = 1;
	//cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}