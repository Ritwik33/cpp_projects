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

int a[2 * 100005];
int b = sqrt(2 * 100005);
multiset<int> ms;

class query {
public:
	int l, r, id;

	bool operator <(const query& q) {
		return (l / b < q.l / b) or (l / b == q.l / b and ((l / b & 1) ? r < q.r : r > q.r));
	}
};

void add(int i) {
	ms.insert(a[i]);
}

void rem(int i) {
	ms.erase(a[i]);
}

void solve() {
	int n, q;
	cin >> n >> q;
	rep(i, 0, n) cin >> a[i];
	vector<query> queries(q);
	rep(i, 0, q) {
		cin >> queries[i].l >> queries[i].r;
		queries[i].l--;
		queries[i].r--;
		queries[i].id = i;
	}
	sort(queries.begin(), queries.end());
	int l = 0, r = -1;
	vi ans(q);
	for (query& qr : queries) {
		while (l > qr.l) add(--l);
		while (r < qr.r) add(++r);
		while (l < qr.l) rem(l++);
		while (r > qr.r) rem(r--);
		ans[qr.id] = *ms.begin();
		l = qr.l;
		r = qr.r;
	}
	for (auto it : ans) cout << it << endl;
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