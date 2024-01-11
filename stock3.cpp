#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

int solve(int i,int buy,int n,int cap,vector<int>&nums,vector<vector<vector<int>>> &dp)
{
if(i>=n || cap<=0)return 0;
int profit=0;
if(dp[i][buy][cap]!=-1)return dp[i][buy][cap];
if(buy)
{
profit=max(
    -nums[i]+solve(i+1,0,n,cap,nums,dp),
     0+solve(i+1,1,n,cap,nums,dp)

);
}
else
{
profit=max(
    nums[i]+solve(i+1,1,n,cap-1,nums,dp),
0+solve(i+1,0,n,cap,nums,dp)
);
}

return dp[i][buy][cap]=profit;


}
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(3, -1)));

       return solve(0,1,n,2,prices,dp);
    }
};