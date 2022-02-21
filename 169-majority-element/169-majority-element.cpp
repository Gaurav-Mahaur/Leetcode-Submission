class Solution {
public:
    int majorityElement(vector<int>& nums)
    {
        map<int,int>mp;
        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]]++;
        }
        int k=0;
        for(auto it:mp)
        {
            if(it.second>nums.size()/2)
            {
                k = it.first;
                break;
            }
        }
        return k;
    }
};