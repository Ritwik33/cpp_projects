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

int dp[100001];
vi arr;

int coins(int n)
{
	if (n == 0)
		return 0;

	if (dp[n] != -1)
		return dp[n];

	dp[n] = inf;

	for (int c : arr)
		if (c <= n)
			dp[n] = min(dp[n], coins(n - c) + 1);

	return dp[n];
}

int32_t main()
{
	FIO;
	int k, n; cin >> k >> n;

	while (k--)
	{
		int x; cin >> x;
		arr.pb(x);
	}

	memset(dp, -1, sizeof(dp));
	int ans = coins(n);



	if (ans == inf)
		cout << "Not Possible\n";

	else
		cout << ans << '\n';
	return 0;
}