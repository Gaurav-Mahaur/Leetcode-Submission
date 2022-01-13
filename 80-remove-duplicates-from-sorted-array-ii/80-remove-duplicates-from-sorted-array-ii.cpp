class Solution {
public:
    int removeDuplicates(vector<int>& nums) 
    {
        int n = nums.size();
        vector<int>a;
        map<int,int>mp;
        for(int i=0;i<n;i++)
        {
            mp[nums[i]]++;
        }
        for(auto it:mp)
        {
            int k = it.second;
            if(k>2)
            {
                for(int i=0;i<2;i++)
                {
                    a.push_back(it.first);
                }
            }
            else
            {
                for(int i=0;i<it.second;i++)
                {
                    a.push_back(it.first);
                }
            }
        }
        int cnt= a.size();
        for(int i=0;i<a.size();i++)
        {
            nums[i] = a[i];
        }
        
        return cnt;
        
    }
};