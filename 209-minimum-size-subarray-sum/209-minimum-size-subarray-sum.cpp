class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums)
    {
        int n = nums.size();
    
        int ans=INT_MAX;
        int currsum=0;
        int i=0;
        int j=0;
       while(i<n)
    {
        currsum += nums[i];
        if(currsum>=target)
        {
            while(currsum>=target)
            {
                currsum-= nums[j];
                ans = min(ans,i-j+1);
                j++;
            }
            ans = min(ans,i-j+1);
        }
        i++;
    }
        if(ans==INT_MAX)
        {
            return 0;
        }
        else
        {
            return ans+1;
        }
        
    }
};