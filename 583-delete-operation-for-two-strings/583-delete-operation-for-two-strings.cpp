class Solution {
public:
    int lcs(string s1,string s2,int n,int m)
    {
        vector<vector<int> >dp(n+1,vector<int>(m+1));
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=m;j++)
            {
                if(i==0||j==0)
                {
                    dp[i][j]=0;
                }
            }
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(s1[i-1]==s2[j-1])
                {
                    dp[i][j] = 1+dp[i-1][j-1];
                }
                else
                {
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[n][m];
        
    }
    int minDistance(string word1, string word2) 
    {
        int n = word1.size();
        int m = word2.size();
        
        int k = lcs(word1,word2,n,m);
        
        int a1 = n-k;
        int a2 = m-k;
        return a1+a2;
        
    }
};