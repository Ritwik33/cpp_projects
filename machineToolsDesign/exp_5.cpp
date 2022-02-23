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
#define ps(x)                                                      fixed << setprecision(1) << x
#define w(q)                                                       int q; cin >> q; while(q--)
#define FIO                                                        ios_base::sync_with_stdio(false); cin.tie(NULL);

int n1, nz, z, vc;
const double pi = 3.141592654, m = 1;

void geometric() {
	double base = (double)nz / (double)n1;
	double power = (double)1 / (double)(z - 1);
	double phi = pow(base, power);
	double n = n1;
	cout << "geometric series(phi : " << phi << " );" << endl;
	rep(i, 1, z + 1) {
		cout << n << endl;
		n *= phi;
	}
	cout << endl;
}

void harmonic() {
	double C = (double)(nz - n1) / (double)(n1 * nz * (z - 1));
	double n = n1;
	cout << "harmonic series(C : " << C << " );" << endl;
	rep(i, 1, z + 1) {
		cout << n << endl;
		n = (double)n / (double)(1 - C * n);
	}
	cout << endl;
}

pair<double, double> points(double d, double m) {
	double ans = d;
	rep(i, 2, z + 1) {
		ans -= 2 * m * sqrt(ans);
	}
	return {ans, m};
}

double interpolate(const pair<double, double>& p1, const pair<double, double>& p2, double dz) {
	double first_term = (double)((dz - p1.first) * (p1.second - p2.second)) / (double)(p1.first - p2.first);
	double ans = (double)(first_term + p1.second);
	return ans;
}

void logarithmic() {
	double d1 = (double)(1000 * vc) / (double)(pi * n1), dz = (double)(1000 * vc) / (double)(pi * nz);
	pair<double, double> A = points(d1, 0.75);
	pair<double, double> B = points(d1, 0.5);
	double m = interpolate(A, B, dz);
	double d = d1;
	cout << "logarithmic series(m : " << m << " );" << endl;
	rep(i, 1, z + 1) {
		cout << d << endl;
		d -= 2 * m * sqrt(d);
	}
	cout << endl;
}

void solve() {
	cin >> n1 >> nz >> z >> vc;
	geometric();
	harmonic();
	logarithmic();
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