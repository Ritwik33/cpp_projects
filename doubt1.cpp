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

set<char> st = {'h', 'e', 'l', 'o'};

void solve() {
	string s;
	cin >> s;
	string h = "hello";
	unordered_map<char, int> mpp;
	rep(i, 0, h.size()) mpp[h[i]]++;
	if (s.size() < 5) {
		cout << "NO" << endl;
	} else if (s.size() == 5) {
		int flag = 0;
		rep(i, 0, s.size()) {
			if (h[i] != s[i]) {
				flag = 1;
				break;
			}
		}
		flag ? (cout << "NO" << endl) : (cout << "YES" << endl);
	} else {
		unordered_map<char, int> freq;
		rep(i, 0, s.size()) {
			if (!st.count(s[i])) {
				cout << "NO" << endl;
				return;
			}
			freq[s[i]]++;
		}
		int fl = 0;
		rep(i, 0, h.size()) {
			if (freq[h[i]] < mpp[h[i]]) {
				fl = 1;
				break;
			}
		}
		fl ? (cout << "NO" << endl) : (cout << "YES" << endl);
	}
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