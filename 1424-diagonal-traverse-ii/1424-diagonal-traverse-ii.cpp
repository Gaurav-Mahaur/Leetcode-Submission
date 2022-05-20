class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) 
    {
        
        int n = nums.size();
        map<int,vector<int> >mp;
        for(int i=0;i<nums.size();i++)
        {
            for(int j=0;j<nums[i].size();j++)
            {
                mp[i+j].push_back(nums[i][j]);
            }
        }
        vector<int>ans;
        for(auto it:mp)
        {
            vector<int>t = it.second;
            reverse(t.begin(),t.end());
            for(int i=0;i<t.size();i++)
            {
                ans.push_back(t[i]);
            }
        }
        return ans;
        
    }
};