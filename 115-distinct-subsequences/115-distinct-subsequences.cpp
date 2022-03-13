class Solution {
public:
    int fun(int idx,string s,int n,string t,string temp)
    {
        if(idx==n)
        {
            if(temp==t)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
        temp += s[idx];
        int take = fun(idx+1,s,n,t,temp);
        temp.pop_back();
        
        int nottake = fun(idx+1,s,n,t,temp);
        
        return take + nottake;
    }
    int fun2(string s,string t,int n,int m,vector<vector<int>>&dp)
    {
        if(m==0)
        {
            return 1;
        }
        if(n==0)
        {
            return 0;
        }
        if(dp[n][m]!=-1)
        {
            return dp[n][m];
        }
        
        if(s[n-1]==t[m-1])
        {
            return dp[n][m]=fun2(s,t,n-1,m-1,dp)+fun2(s,t,n-1,m,dp);
        }
        return dp[n][m] = fun2(s,t,n-1,m,dp);
    }
    int numDistinct(string s, string t) 
    {
        int n = s.size();
        int m = t.size();
        vector<vector<double>>dp(n+1,vector<double>(m+1));
        
        //return fun2(s,t,n,m,dp);
        for(int i=0;i<=n;i++)
        {
            dp[i][0]=1;
        }
        for(int i=1;i<=m;i++)
        {
            dp[0][i]=0;
        }
        
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(s[i-1]==t[j-1])
                {
                    dp[i][j]=dp[i-1][j-1]+dp[i-1][j];
                }
                else
                {
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        
        return (int)dp[n][m];
    }
    
};