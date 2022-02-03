#include<bits/stdc++.h>
using namespace std;

#define endl                                                       '\n'
#define inf                                                        1e18
#define mod                                                        1000000007
#define int                                                        long long
#define vi                                                         vector<int>
#define vvi                                                        vector<vector<int>>
#define pb(x)                                                      push_back(x)
#define ppb                                                        pop_back()
#define rep(i, a, b)                                               for(int i = a;i<b;i++)
#define repd(i, a)                                                 for(int i = a;i>=0;i--)
#define setbits(x)                                                 __builtin_popcountll(x)
#define ps(x, y)                                                   fixed << setprecision(y) << x
#define w(q)                                                       int q; cin >> q; while(q--)
#define FIO                                                        ios_base::sync_with_stdio(false); cin.tie(NULL);

class strength {
public:
	int x, y;
	bool operator<(const strength& s) {
		return x < s.x or (x == s.x and y > s.y);
	}
};

void solve() {
	int s, n; cin >> s >> n;
	vector<strength> strengths(n);
	rep(i, 0, n) {
		cin >> strengths[i].x >> strengths[i].y;
	}
	sort(strengths.begin(), strengths.end());
	int total = s;
	int flag = 1;
	for (auto it : strengths) {
		if (it.x > total) {
			flag = 0;
			break;
		}
		total += it.y;
	}
	flag ? cout << "YES" << endl : cout << "NO" << endl;
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