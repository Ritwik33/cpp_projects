//https://practice.geeksforgeeks.org/problems/longest-common-substring1452/1

class Solution {
public:

	int longestCommonSubstr (string S1, string S2, int n, int m)
	{
		// your code here
		int dp[n][m], ans = 0;

		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j)
			{
				if (S1[i] == S2[j])
				{
					dp[i][j] = 1;
					if (i and j)
						dp[i][j] += dp[i - 1][j - 1];
				}
				else
					dp[i][j] = 0;

				ans = max(ans, dp[i][j]);
			}

		return ans;
	}
};