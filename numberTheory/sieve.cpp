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

const int n = 1000000;
vector<char> sieve(1000006, 'p');

void precompute_sieve() {
	sieve[0] = sieve[1] = 'n';
	for (int i = 2; i * i <= n; i++) {
		if (sieve[i] == 'p') {
			for (int j = i * i; j <= n; j += i) {
				sieve[j] = 'c';
			}
		}
	}
}

int spf[1000006];

void precompute_spf() {
	for (int i = 0; i <= n; i++) spf[i] = i;
	for (int i = 2; i * i <= n; i++) {
		if (spf[i] == i) {
			for (int j = i * i; j <= n; j += i) {
				if (spf[j] == j) spf[j] = i;
			}
		}
	}
}

int lpf[1000006];

void precompute_lpf() {
	for (int i = 0; i <= n; i++) lpf[i] = i;
	for (int i = 2; i * i <= n; i++) {
		if (lpf[i] == i) {
			for (int j = 2 * i; j <= n; j += i) {
				lpf[j] = i;
			}
		}
	}
}

void print_prime_factor(int num) {
	while (num > 1) {
		cout << spf[num] << ' ';
		num /= spf[num];
	}
	cout << endl;
}

vector<int> precompute_segmented_sieve(int l, int r) {
	vector<int> primes(r - l + 1, 1);
	if (l == 1) primes[0] = 0;
	for (int i = 2; i * i <= r; i++) {
		int num = ((l + i - 1) / i) * i;
		for (int j = max(num, i * i); j <= r; j += i) {
			primes[j - l] = 0;
		}
	}
	return primes;
}

void solve() {

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