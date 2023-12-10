#include<bits/stdc++.h>
using namespace std;

const int N=1e3;
const int M=1e3;
int dp[N][M];
int coins[3];

int findways(int n,int k)
{
if(n==0)
{
if(k==0)return 1;
return 0;

}

if(dp[n][k]!=-1)return dp[n][k];

int ans1=findways(n-1,k);
int ans2;
while(1)
{
if(k<coins[n])break;
 ans2=findways(n,k-coins[n]);

}

int ans=min(ans1,ans2);

dp[n][k]=ans;
return ans;

}

int main()
{
int amount;
for(int i=0;i<3;i++)
{
cin>>coins[i];

};

cin>>amount;


for(int i=0;i<N;i++)
{
for(int j=0;j<M;j++)
{
dp[i][j]=-1;

}

}

int res=findways(2,amount);
cout<<res;
}