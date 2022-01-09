#include<bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//using namespace __gnu_pbds;
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

//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

int n;
vi adj[1000001];
int a[1000001], dp[1000001], leaves[1000001];

void dfs(int i = 1, int par = 0)
{
	dp[i] = inf, leaves[i] = 0;

	int sum_of_children = 0, got_inf = 0;

	for (int j : adj[i])
	{
		if (j == par)
			continue;

		dfs(j, i);
		leaves[i] += leaves[j];

		if (dp[j] == inf)
			got_inf = 1;

		sum_of_children += dp[j];
	}

	if (!leaves[i])
	{
		leaves[i] = 1;
		dp[i] = (a[i] == 0) ? inf : a[i];
	}

	else
	{
		// khud ko non-zero
		if (a[i] != 0)
			dp[i] = leaves[i] * a[i];

		// khud ko zero
		if (got_inf == 0)
			dp[i] = min(dp[i], sum_of_children);
	}
}

int32_t main()
{
	FIO;
	w(t)
	{
		cin >> n;

		for (int i = 1; i <= n; ++i)
			adj[i].clear();

		for (int i = 0; i < n - 1; ++i)
		{
			int u, v; cin >> u >> v;
			adj[u].pb(v);
			adj[v].pb(u);
		}

		for (int i = 1; i <= n; ++i)
			cin >> a[i];

		dfs();
		cout << dp[1] << '\n';
	}
	return 0;
}