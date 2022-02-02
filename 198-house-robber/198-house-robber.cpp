class Solution {
public:
    int fun(int idx,vector<int>nums,vector<int>&dp)
    {
        if(idx==0)
        {
            return nums[idx];
        }
        if(idx<0)
        {
            return 0;
        }
        if(dp[idx]!=-1)
        {
            return dp[idx];
        }
        int pick = nums[idx]+fun(idx-2,nums,dp);
        int notpick = 0+fun(idx-1,nums,dp);
        
        return dp[idx]=max(pick,notpick);
        
    }
    int rob(vector<int>& nums) 
    {
        int n = nums.size();
        if(n==1)
        {
            return nums[0];
        }
        vector<int>dp(n,-1);
        return fun(n-1,nums,dp);
        
    }
};