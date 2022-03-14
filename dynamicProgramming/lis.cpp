//https://leetcode.com/problems/longest-increasing-subsequence/

// O(n*n)

class Solution {
public:
	int lengthOfLIS(vector<int>& nums) {
		vector<int> dp(nums.size(), 1);

		for (int i = 1; i < nums.size(); ++i)
			for (int j = 0; j < i; ++j)
				if (nums[j] < nums[i])
					dp[i] = max(dp[i], dp[j] + 1);

		return *max_element(dp.begin(), dp.end());
	}
};

// https://leetcode.com/problems/longest-increasing-subsequence/

// O(nlogn)

class Solution {
public:
	int lengthOfLIS(vector<int>& nums) {
		vector<int> dp;

		for (int i : nums)
		{
			auto it = lower_bound(dp.begin(), dp.end(), i);

			if (it == dp.end())
				dp.push_back(i);

			else
				(*it) = i;
		}

		return dp.size();
	}
};