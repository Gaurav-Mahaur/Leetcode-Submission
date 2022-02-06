class Solution {
public:
    int longestPalindromeSubseq(string s) 
    {
        int n= s.size();
        if(n==1)
        {
            return 1;
        }
        string rev = s;
        reverse(rev.begin(),rev.end());
        vector<vector<int>>dp(1005,vector<int>(1005));
        
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=n;j++)
            {
                if(i==0||j==0)
                {
                    dp[i][j]=0;
                }  
            }
        }
        
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(s[i-1]==rev[j-1])
                {
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else
                {
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[n][n];
        //return 0;
        
    }
};