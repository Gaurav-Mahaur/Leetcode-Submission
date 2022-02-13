class Solution {
public:
    
    vector<vector<int>> subsets(vector<int>& nums)
    {
        int n = nums.size();
        vector<int>a;
        vector<vector<int> > v;
        
        for(int i=0;i<(1<<n);i++)
        {
            a.clear();
            for(int j=0;j<n;j++)
            {
                if(i&(1<<j))
                {
                    a.push_back(nums[j]);
                }
            }
            v.push_back(a);
        }
        
        return v;
        
    }
};