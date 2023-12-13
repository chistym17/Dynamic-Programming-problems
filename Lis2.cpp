#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
      int topDown(vector<int>& nums,int curr,int prev,vector<vector<int>>& dp){
         if(curr>=nums.size()){
            return 0;
        }
        if(dp[curr][prev+1]!=-1)
            return dp[curr][prev+1];
        int include=0;
        if(prev==-1||nums[curr]>nums[prev])
            include=1+topDown(nums,curr+1,curr,dp);
        
        //exclude
        int exclude=topDown(nums,curr+1,prev,dp);
        dp[curr][prev+1]= max(include,exclude);
        return dp[curr][prev+1];
    }
    int lengthOfLIS(vector<int>& nums) {
         int prev=-1,curr=0;
        vector<vector<int>> dp(nums.size()+1,vector<int>(nums.size()+1,-1));
        return topDown(nums,curr,prev,dp);
    }
};