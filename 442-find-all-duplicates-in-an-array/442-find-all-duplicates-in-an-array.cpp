class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) 
    {
        int n = nums.size();
        vector<int>ans;
        if(n==1)
        {
            return {};
        }
        for(int i=0;i<n;i++)
        {
           nums[abs(nums[i])-1]= -nums[abs(nums[i])-1];
            if(nums[abs(nums[i])-1]>0)
            {
                ans.push_back(abs(nums[i]));
            }
        }
        return ans;
        
    }
};