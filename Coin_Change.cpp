#include<bits/stdc++.h>
using namespace std;



class Solution {
public:
    int findMinimumWays(vector<int>& nums, int amount, vector<int>& dp) {
        if (amount == 0) return 0;
        if (dp[amount] != -1) return dp[amount];

        int ans = INT_MAX;
        for (int i = 0; i < nums.size(); i++) {
            if (amount < nums[i]) continue;

            int subans = findMinimumWays(nums, amount - nums[i], dp);

            if (subans != INT_MAX && subans + 1 < ans) {
                ans = subans + 1;
            }
        }

        dp[amount] = ans;
        return dp[amount];
    }

    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, -1);
        dp[0] = 0;

        int ans = findMinimumWays(coins, amount, dp);
        if (ans == INT_MAX)  return -1 ;
        return ans;
    }
};





