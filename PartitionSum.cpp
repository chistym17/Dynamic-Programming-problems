#include<bits/stdc++.h>
using namespace std;




class Solution {
public:

bool subset(vector<int>&nums,int n,int sum,vector<vector<int>>&dp)
{
    if(sum==0){
        return true;
    }
    
    if(n==0){
        return nums[0]==sum;
    }


if(dp[n][sum]!=-1)return dp[n][sum];
int take=false;
if(sum>=nums[n])
take=subset(nums,n-1,sum-nums[n],dp);

int not_take=subset(nums,n-1,sum,dp);

return dp[n][sum]=take || not_take;

}

    bool canPartition(vector<int>& nums) {
        int totalsum=0;
        int n=nums.size();
        for(int i=0;i<nums.size();i++)
        {
          totalsum+=nums[i];

        }
        if(totalsum%2!=0)return false;
        int sum=totalsum/2;

        vector<vector<int>>dp(n+1,vector<int>(sum+1,-1));
        if(subset(nums,n-1,sum,dp))return true;

        return false;
    }
};