// https://leetcode.com/problems/longest-common-subsequence/

class Solution {
public:
	int longestCommonSubsequence(string s, string t) {
		int n = s.length(), m = t.length();

		int dp[n][m];

		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j)
			{
				int &cur = dp[i][j];
				cur = (s[i] == t[j]);

				if (i)
					cur = max(cur, dp[i - 1][j]);

				if (j)
					cur = max(cur, dp[i][j - 1]);

				if (i and j and s[i] == t[j])
					cur = max(cur, dp[i - 1][j - 1] + 1);
			}

		return dp[n - 1][m - 1];
	}
};