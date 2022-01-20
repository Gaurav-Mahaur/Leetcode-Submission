class Solution {
public:
    int climbStairs(int n) 
    {
       int dp[n+1];
        dp[0]=0;
        dp[1]=1;
        if(n<=1)
        {
            return dp[n];
        }
        dp[2]=2;
        for(int i=3;i<=n;i++)
        {
            dp[i] = dp[i-1]+dp[i-2];
        }
        
        int k = dp[n];
        return k;
        
    
        
    }
};