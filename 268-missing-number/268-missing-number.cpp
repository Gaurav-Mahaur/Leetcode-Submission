class Solution {
public:
    int missingNumber(vector<int>& nums)
    {
        int n = nums.size();
        
        int xorsum=0;
        for(int i=0;i<n;i++)
        {
            xorsum =xorsum^nums[i];
        }
        for(int i=0;i<=n;i++)
        {
            xorsum = xorsum^i;
        }
        
        return xorsum;
    }
};