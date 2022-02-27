class Solution {
public:
    int minsum(vector<int>&nums,int n)
    {
        int currsum = 0;
        int minn = INT_MAX;
        
        for(int i=0;i<n;i++)
        {
            currsum += nums[i];
            minn = min(minn,currsum);
            if(currsum>=0)
            {
                currsum =0;
            }
        }
        return minn;
    }
    int maxsum(vector<int>&nums,int n)
    {
        int currsum = 0;
        int maxx = INT_MIN;
        
        for(int i=0;i<n;i++)
        {
            currsum += nums[i];
           maxx = max(maxx,currsum);
            if(currsum<0)
            {
                currsum =0;
            }
        }
        return maxx;
    }
    int maxSubarraySumCircular(vector<int>& nums) 
    {
        int n = nums.size();
        if(n==0)
        {
            return 0;
        }
        int flag=1;
        int maxi = INT_MIN;
        for(int i=0;i<n;i++)
        {
            if(nums[i]>=0)
            {
                flag=0;
                break;
            }
            maxi = max(maxi,nums[i]);
        }
        if(flag)
        {
            return maxi;
        }
        
        int ans1 = maxsum(nums,n);
        int sum=0;
        for(int i=0;i<n;i++)
        {
            sum += nums[i];
        }
        int ans2 = sum - minsum(nums,n);
        
        return max(ans1,ans2);
        
    }
};