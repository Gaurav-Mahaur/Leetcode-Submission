class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) 
    {
        int n = nums.size();
        map<int,int>mp;
        int currsum=0;
        if(n<=1)
        {
            return false;
        }
        for(int i=0;i<n;i++)
        {
            currsum += nums[i];
            
            currsum = currsum%k;
            if(currsum==0 && i>0)
            {
                return true;
            }
            
            if(mp.find(currsum)!=mp.end())
            {
                if(i-mp[currsum]>1)
                {
                    return true;
                }
            }
            else
            {
                mp[currsum]=i;
            }
            
        }
        return false;
        
    }
};