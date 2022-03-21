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

bool dp[50001][32];

bool check(string &s, int i, int m)
{
	for (int d = 0; d < 5; ++d)
		if (s[i - d] != '?' and (s[i - d] - '0') != ((m >> d) & 1))
			return false;

	return true;
}

bool pal(int mask, int len)
{
	for (int i = 0, j = len - 1; i < j; ++i, --j)
		if (((mask >> i) & 1) != ((mask >> j) & 1))
			return false;

	return true;
}

int32_t main()
{
	FIO;
	int tc; cin >> tc;
	for (int tnum = 1; tnum <= tc; ++tnum)
	{
		int n; cin >> n;
		string s, ans = "IMPOSSIBLE"; cin >> s;

		if (n < 5)
			ans = "POSSIBLE";

		else
		{
			// i < 4

			// i = 4, exactly 5 characters
			for (int m = 0; m < 32; ++m)
				dp[4][m] = check(s, 4, m) && (!pal(m, 5));

			for (int i = 5; i < n; ++i)
				for (int m = 0; m < 32; ++m)
				{
					if (!check(s, i, m) or pal(m, 5))
						dp[i][m] = 0;

					else
					{
						dp[i][m] = 0;

						// Explore when s[i-5] = '0'
						if (dp[i - 1][m >> 1] and !pal(m, 6))
							dp[i][m] = 1;

						// Explore when s[i-5] = '1'
						if (dp[i - 1][(m >> 1) + 16] and !pal(m + 32, 6))
							dp[i][m] = 1;
					}
				}

			for (int m = 0; m < 32; ++m)
				if (dp[n - 1][m])
					ans = "POSSIBLE";
		}

		cout << "Case #" << tnum << ": " << ans << '\n';
	}
	return 0;
}