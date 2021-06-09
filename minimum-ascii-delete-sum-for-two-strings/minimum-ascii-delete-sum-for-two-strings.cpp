class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int n=s1.size(),m=s2.size(),total=0,dp[n+1][m+1];
        for(auto u:s1)
            total+=(int)u;
        for(auto u:s2)
            total+=(int)u;
        for(int i=0;i<=n;i++)
            for(int j=0;j<=m;j++)
            {
                if(i==0||j==0)
                    dp[i][j]=0;
                else
                {
                    if(s1[i-1]==s2[j-1])
                        dp[i][j]=(int)s1[i-1]+dp[i-1][j-1];
                    else
                        dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        return total-2*dp[n][m];
        
    }
};