// https://codeforces.com/problemset/problem/230/A

// if at any point of time kirito cannot defeat a dragon, then it is a loss...
// kirito will win only when he defeats the last dragon...
// defeat the weakest and acquire maximum points in each step...
// this will ensure minimum loss and maximum acquisition at each step...
// which will increases the chances of defeating the last dragon...

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

class Strength {
public:
	int x, y;
	bool operator<(Strength& s) {
		return x < s.x or (x == s.x and y > s.y);
	}
};

void solve() {
	int s, n; cin >> s >> n;
	vector<Strength> strengths;
	rep(i, 0, n) {
		Strength s;
		cin >> s.x >> s.y;
		strengths.push_back(s);
	}
	sort(strengths.begin(), strengths.end());
	bool flag = true;
	for (auto it : strengths) {
		if (s <= it.x) {
			flag = false;
			break;
		}
		s += it.y;
	}
	flag ? (cout << "YES" << endl) : (cout << "NO" << endl);
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