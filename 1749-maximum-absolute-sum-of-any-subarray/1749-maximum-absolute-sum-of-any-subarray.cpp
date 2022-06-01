class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) 
    {
        int n = nums.size();
        int maxx = INT_MIN;
        int cur=0;
        for(int i=0;i<n;i++)
        {
            cur += nums[i];
            if(cur<0)
            {
                cur = 0;
            }
            maxx = max(maxx,cur);
        }
        int minn = INT_MAX;
        int minsum=0;
        for(int i=0;i<n;i++)
        {
            if(minsum>0)
            {
                minsum = nums[i];
            }
            else
            {
                minsum += nums[i];
            }
            
            minn = min(minn,minsum);
        }
        return max(maxx,abs(minn));
        
    }
};