class Solution {
public:
    vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3) 
    {
        set<int>s1,s2,s3;
        for(int i=0;i<nums1.size();i++)s1.insert(nums1[i]);
        for(int i=0;i<nums2.size();i++)s2.insert(nums2[i]);
        for(int i=0;i<nums3.size();i++)s3.insert(nums3[i]);
        
        map<int,int>mp;
        for(auto it:s1)
        {
            mp[it]++;
        }
        for(auto it:s2)
        {
            mp[it]++;
        }
        for(auto it:s3)
        {
            mp[it]++;
        }
        vector<int>v;
        for(auto it:mp)
        {
            if(it.second>1)
            {
                v.push_back(it.first);
            }
        }
        return v;
    }
};