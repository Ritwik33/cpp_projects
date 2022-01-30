// codeforces contest 86 D

#include<bits/stdc++.h>
using namespace std;

#define endl                                                       '\n'
#define inf                                                        1e18
#define int                                                        long long
#define vi                                                         vector<int>
#define vvi                                                        vector<vector<int>>
#define pb(x)                                                      push_back(x)
#define ppb                                                        pop_back()
#define rep(i, a, b)                                               for(int i = a;i<b;i++)
#define repd(i, a)                                                 for(int i = a;i>=0;i--)
#define setbits(x)                                                 __builtin_popcountll(x)
#define FIO                                                        ios_base::sync_with_stdio(false); cin.tie(NULL);

int a[200005];
int b = sqrt(200005);
int sum;
int ans[200005];
int freq[1000006];

void add(int i) {
	int& f = freq[a[i]];
	sum -= f * f * a[i];
	f++;
	sum += f * f * a[i];
}

void rem(int i) {
	int &f = freq[a[i]];
	sum -= f * f * a[i];
	f--;
	sum += f * f * a[i];
}

class query {
public:
	int l, r, id;

	bool operator <(const query& q) {
		return (l / b < q.l / b) or (l / b == q.l / b and r < q.r);
	}
};

void solve() {
	int n, t;
	cin >> n >> t;
	rep(i, 0, n) cin >> a[i];
	vector<query> queries(t);
	rep(i, 0, t) {
		cin >> queries[i].l >> queries[i].r;
		queries[i].l--;
		queries[i].r--;
		queries[i].id = i;
	}
	sort(queries.begin(), queries.end());
	int l = 0, r = -1;
	for (query &q : queries) {
		while (l > q.l) add(--l);
		while (r < q.r) add(++r);
		while (l < q.l) rem(l++);
		while (r > q.r) rem(r--);
		ans[q.id] = sum;
		l = q.l;
		r = q.r;
	}
	rep(i, 0, t) cout << ans[i] << endl;
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