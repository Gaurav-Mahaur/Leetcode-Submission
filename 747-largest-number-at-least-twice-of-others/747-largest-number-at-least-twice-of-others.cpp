class Solution {
public:
    int dominantIndex(vector<int>& nums) 
    {
        int n = nums.size();
        int idx = max_element(nums.begin(),nums.end())-nums.begin();
        sort(nums.begin(),nums.end());
        if(n==1)
        {
            return 0;
        }
        int a= nums[n-1];
        if(a>=2*nums[n-2])
        {
            return idx;
        }
        
        return -1;
        
        
    }
};