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

int32_t main()
{
	FIO;
	int n, m; cin >> n >> m;

	/*int dp[n + 1][m + 1];

	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			if (i == 1 or j == 1)
				dp[i][j] = 1;
			else
				dp[i][j] = dp[i - 1][j] + dp[i][j - 1];

	cout << dp[n][m] << '\n';*/

	/*vi cur(m + 1, 1), last(m + 1); // 1st row

	for (int i = 2; i <= n; ++i)
	{
		last = cur;
		for (int j = 1; j <= m; ++j)
		{
			if (j == 1)
				cur[j] = 1;
			else
				cur[j] = last[j] + cur[j - 1];
		}
	}

	// cur will represent answers of the nth row
	cout << cur[m] << '\n';*/

	vi dp(m + 1, 1); // 1st row ka answer

	for (int i = 2; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			if (j == 1)
				dp[j] = 1;
			else
				dp[j] += dp[j - 1];

	cout << dp[m];
	return 0;
}