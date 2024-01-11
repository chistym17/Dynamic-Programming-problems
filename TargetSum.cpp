#include<bits/stdc++.h>
using namespace std;




class Solution {
public:
    int solve(vector<int>& nums, int n, int target) {
        if (n < 0) {
            return target == 0 ? 1 : 0;
        }

  

       int ans= solve(nums, n - 1, target - nums[n]) + solve (nums, n - 1, target + nums[n]);

        return ans;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        return solve(nums, n - 1, target );
    }
};
