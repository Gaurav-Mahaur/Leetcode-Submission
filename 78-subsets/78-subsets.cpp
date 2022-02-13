class Solution {
public:
    void powerset(int idx,vector<int>nums,int n,vector<int>&a,vector<vector<int> >&v)
    {
        if(idx==n)
        {
            v.push_back(a);
            return;
        }
        a.push_back(nums[idx]);
        powerset(idx+1,nums,n,a,v);
        a.pop_back();
        
        powerset(idx+1,nums,n,a,v);
    }
    vector<vector<int>> subsets(vector<int>& nums)
    {
        int n = nums.size();
        vector<int>a;
        vector<vector<int> > v;
        
        powerset(0,nums,n,a,v);
        
        return v;
        
    }
};