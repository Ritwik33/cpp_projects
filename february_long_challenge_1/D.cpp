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

string parity(int num) {
	if (num & 1) return "odd";
	return "even";
}

bool check_vec(const vector<pair<int, int>>& vec) {
	for (auto it : vec) {
		if (it.second == 100000 + 1) {
			return true;
		}
	}
	return false;
}

void solve() {
	int n; cin >> n;
	int a[n + 1];
	int odds = 0;
	rep(i, 1, n + 1) {
		cin >> a[i];
		if (a[i] & 1) odds++;
	}
	if (odds == 0) {
		cout << "-1" << endl;
		return;
	}
	int flag = 0;
	rep(i, 1, n) {
		if (parity(a[i]) == parity(a[i + 1])) {
			flag = 1;
			break;
		}
	}
	if (!flag) {
		cout << "0" << endl;
		return;
	}
	int odd_1_index = 0, odd_2_index = 100000 + 1;
	int odd_1_val, odd_2_val = (1 << 30) + 1;
	rep(i, 1, n + 1) {
		if (a[i] & 1) {
			if (odd_1_index == 0) {
				odd_1_index = i;
				odd_1_val = a[i];
			} else if (odd_2_index == 100000 + 1) {
				odd_2_index = i;
				odd_2_val = a[i];
			}
		}
	}
	int a_clone[n + 1];
	rep(i, 1, n + 1) {
		a_clone[i] = a[i];
	}
	vector<pair<int, int>> start_vector, end_vector;
	int start_operations = 0, end_operations = 0;
	rep(i, 2, n + 1) {
		if (parity(a[i]) == parity(a[i - 1])) {
			start_operations++;
			if (parity(a[i]) == "even") {
				a[i] = a[i] ^ odd_1_val;
				start_vector.push_back({i, odd_1_index});
			} else {
				if (a[i] == odd_1_val) {
					a[i] = a[i] ^ odd_2_val;
					start_vector.push_back({i, odd_2_index});
				} else if (a[i] == odd_2_val) {
					a[i] = a[i] ^ odd_1_val;
					start_vector.push_back({i, odd_1_index});
				}
			}
		}
	}
	for (int i = n - 1; i >= 1; i--) {
		if (parity(a_clone[i]) == parity(a_clone[i + 1])) {
			end_operations++;
			if (parity(a_clone[i]) == "even") {
				a_clone[i] = a_clone[i] ^ odd_1_val;
				end_vector.push_back({i, odd_1_index});
			} else {
				if (a_clone[i] == odd_1_val) {
					a_clone[i] = a_clone[i] ^ odd_2_val;
					end_vector.push_back({i, odd_2_index});
				} else if (a_clone[i] == odd_2_val) {
					a_clone[i] = a_clone[i] ^ odd_1_val;
					end_vector.push_back({i, odd_1_index});
				}
			}
		}
	}
	bool v_start, v_end;
	v_start = check_vec(start_vector);
	v_end = check_vec(end_vector);
	if (v_start and v_end) {
		cout << "-1" << endl;
		return;
	} else if (v_start or v_end) {
		if (v_start) {
			cout << end_operations << endl;
			for (auto it : end_vector) {
				cout << it.first << ' ' << it.second << endl;
			}
		} else {
			cout << start_operations << endl;
			for (auto it : start_vector) {
				cout << it.first << ' ' << it.second << endl;
			}
		}
	} else if (!v_start and !v_end) {
		if (start_operations <= end_operations) {
			cout << start_operations << endl;
			for (auto it : start_vector) {
				cout << it.first << ' ' << it.second << endl;
			}
		} else {
			cout << end_operations << endl;
			for (auto it : end_vector) {
				cout << it.first << ' ' << it.second << endl;
			}
		}
	}
}

int32_t main() {
	FIO;

// #ifndef ONLINE_JUDGE
// 	freopen("input.txt", "r", stdin);
// 	freopen("output.txt", "w", stdout);
// #endif

	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}