class Solution {
 int dp[1005][1005];

int lcs(string a,string b, int i,int j)
{
if(i==a.length() || j==b.length())return 0;
if(dp[i][j]!=-1)return dp[i][j];

if(a[i]==b[j])return dp[i][j]= 1+lcs(a,b,i+1,j+1);
else
return dp[i][j]= max(lcs(a,b,i+1,j),lcs(a,b,i,j+1));


}

public:
    int longestCommonSubsequence(string text1, string text2) {
        for(int i=0;i<text1.length();i++)
        {
         for(int j=0;j<text2.length();j++)
         {

             dp[i][j]=-1;
         };

        };


        return lcs(text1,text2,0,0);
        
    }
};