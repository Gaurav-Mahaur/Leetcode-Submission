class Solution {
public:
    int fun(vector<int>&coins,int n,int target,vector<vector<int>>&dp)
    {
        if(n==0 || target==0)
        {
            if(target==0)
            {
                return 0;
            }
            else
            {
                return INT_MAX-1;
            }
        }
        if(dp[n][target]!=-1)
        {
            return dp[n][target];
        }
        if(coins[n-1]<=target)
        {
            return dp[n][target] = min(1+fun(coins,n,target-coins[n-1],dp),fun(coins,n-1,target,dp));
        }
        return dp[n][target]= fun(coins,n-1,target,dp);
    }
    int coinChange(vector<int>& coins, int amount) 
    {
        int n = coins.size();
        vector<vector<int>>dp(n+1,vector<int>(amount+1,-1));
        
       int minn=  fun(coins,n,amount,dp);
        
        if(minn==INT_MAX -1)
        {
            return -1;
        }
        return minn;
    }
};