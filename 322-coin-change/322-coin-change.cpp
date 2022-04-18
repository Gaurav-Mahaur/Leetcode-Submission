class Solution {
public:
    int dp[10000 + 1][12 + 1];
    
    int fun(vector<int>&a,int n,int target)
    {
        if (n == 0 || target == 0)
        {
            return (target == 0) ? 0 : INT_MAX - 1;
        }  
        
        if (dp[target][n] != -1) 
            return dp[target][n];
        if(a[n-1]<=target)
        {
            return dp[target][n]=min(1+fun(a,n,target-a[n-1]),fun(a,n-1,target));
        }
        return dp[target][n]=fun(a,n-1,target);
    }
    int coinChange(vector<int>& coins, int amount) 
    {
         memset(dp, -1, sizeof(dp));
        int n = coins.size();
        int mincoin = fun(coins,n,amount);
        if(mincoin==INT_MAX-1)
        {
            return -1;
        }
        return mincoin;
        
        
    }
};