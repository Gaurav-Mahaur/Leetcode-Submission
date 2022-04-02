class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) 
    {
        vector<int>ans;
        set<int>st;
        int n = nums.size();
        for(int i=0,j = 0;i<n;i++)
        {
            if(nums[i]==key)
            {
                for (j = max(j, i - k); j <= i + k && j < nums.size(); ++j)
                {
                    ans.push_back(j);
                }
            }
        }
        return ans;
        
        
    }
};