class Solution {
public:
    vector<int> findLonely(vector<int>& nums) 
    {
        map<int,int>mp;
        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]]++;
        }
        vector<int>v;
        for(int i=0;i<nums.size();i++)
        {
            if(mp[nums[i]]==1)
            {
                if(mp.find(nums[i]-1)==mp.end() && mp.find(nums[i]+1)==mp.end())
                {
                    v.push_back(nums[i]);
                }
            }
        }
        return v;
        
    }
};