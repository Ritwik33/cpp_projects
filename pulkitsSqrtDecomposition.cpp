#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

#define ff              first
#define ss              second
#define int             long long
#define pb              push_back
#define mp              make_pair
#define mt              make_tuple
#define pii             pair<int,int>
#define vi              vector<int>
#define mii             map<int,int>
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int> >
#define setbits(x)      __builtin_popcountll(x)
#define mod             1000000007
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define range(a,b)		substr(a,b-a+1)
#define w(x)            int x; cin>>x; while(x--)
#define trace(x) 		cerr<<#x<<": "<<x<<" "<<endl;
#define FIO             ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

int n, q, b;
int a[200000], sum[450];

void update(int id, int val) // 0-based
{
	sum[id / b] -= a[id];
	a[id] = val;
	sum[id / b] += a[id];
}

int query(int l, int r) // 0-based
{
	int lb = l / b, rb = r / b, ans = 0;

	if (lb == rb)
	{
		for (int i = l; i <= r; ++i)
			ans += a[i];
		return ans;
	}

	int rb_start = rb * b, lb_end = (lb + 1) * b - 1;

	// Add the values of l block
	for (int i = l; i <= lb_end; ++i)
		ans += a[i];

	// Add the values of r block
	for (int i = rb_start; i <= r; ++i)
		ans += a[i];

	// Add the sums of intermediate blocks
	for (int i = lb + 1; i < rb; ++i)
		ans += sum[i];

	return ans;
}

int32_t main()
{
	FIO;
	cin >> n >> q;

	b = sqrt(n);

	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
		sum[i / b] += a[i];
	}

	while (q--)
	{
		int tp; cin >> tp;

		if (tp == 1)
		{
			int id, val; cin >> id >> val;
			update(id - 1, val);
		}

		else
		{
			int l, r; cin >> l >> r;
			cout << query(l - 1, r - 1) << '\n';
		}
	}
	return 0;
}