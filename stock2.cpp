
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

int solve(int i,int buy,int n,vector<int>&nums,vector<vector<int>>&dp)
{
if(i>=n)return 0;
int profit=0;
if(dp[i][buy]!=-1)return dp[i][buy];
if(buy)
{
profit=max(
    -nums[i]+solve(i+1,0,n,nums,dp),
     0+solve(i+1,1,n,nums,dp)

);
}
else
{
profit=max(
    nums[i]+solve(i+1,1,n,nums,dp),
0+solve(i+1,0,n,nums,dp)
);
}

return dp[i][buy]=profit;


}
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
       vector<vector<int>>dp(n+1,vector<int>(2,-1));
       return solve(0,1,n,prices,dp);
    }
};