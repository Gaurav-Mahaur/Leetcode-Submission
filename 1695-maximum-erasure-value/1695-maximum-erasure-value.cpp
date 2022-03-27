class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) 
    {
        int n = nums.size();
        set<int>s;
        int l=0;
        int r=0;
        int currsum=0;
        int maxx = INT_MIN;
        while(r<n)
        {
            while(s.find(nums[r])!=s.end() && l<r)
            {
                currsum -= nums[l];
                s.erase(nums[l]);
                l++;
                
            }
            currsum += nums[r];
            maxx = max(maxx,currsum);
            
            s.insert(nums[r]);
            r++;
        }
        return maxx;
    }
};