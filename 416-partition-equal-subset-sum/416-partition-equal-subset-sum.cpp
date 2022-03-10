class Solution {
public:
    bool helping(vector<int>&nums,int n,int target)
    {
        if(target==0)
        {
            return true;
        }
        if(n==0)
        {
            return false;
        }
        if(nums[n-1]<=target)
        {
            return helping(nums,n-1,target-nums[n-1])||helping(nums,n-1,target);
        }
        return helping(nums,n-1,target);
    }
    bool canPartition(vector<int>& nums) 
    {
        int n = nums.size();
        int s=0;
        for(int i=0;i<n;i++)
        {
            s += nums[i];
        }
        if(s%2==1)
        {
            return false;
        }
        int k = s/2;
        vector<vector<bool>>dp(n+1,vector<bool>(k+1));
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=k;j++)
            {
                if(i==0)
                {
                    dp[i][j]=false;
                }
                if(j==0)
                {
                    dp[i][j]=true;
                }
            }
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=k;j++)
            {
                if(nums[i-1]<=j)
                {
                    dp[i][j] = dp[i-1][j-nums[i-1]] || dp[i-1][j];
                }
                else
                {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        
        return dp[n][k];
    }
};