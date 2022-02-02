class Solution {
public:
    int fun(int idx,vector<int>&nums,int n,int orsum,int k,vector<int>&dp)
    {
        if(idx==n)
        {
            if(orsum==k)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
        int take = fun(idx+1,nums,n,orsum|nums[idx],k,dp);
        int nottake =fun(idx+1,nums,n,orsum,k,dp);
        return dp[idx] = take+nottake;
    }
    int countMaxOrSubsets(vector<int>& nums) 
    {
        int n = nums.size();
        if(n==1)
        {
            return 1;
        }
        vector<int>dp(n+1,-1);
        int k=0;
        for(int i=0;i<n;i++)
        {
            k = k|nums[i];
        }
        return fun(0,nums,n,0,k,dp);
        
    }
};