class Solution {
public:
    int singleNumber(vector<int>& nums)
    {
        int n = nums.size();
        int xorsum =nums[0];
        for(int i=1;i<n;i++)
        {
            xorsum = xorsum^nums[i];
        }
        return xorsum;
    }
};