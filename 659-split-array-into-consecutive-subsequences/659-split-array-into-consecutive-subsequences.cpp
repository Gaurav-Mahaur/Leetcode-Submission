class Solution {
public:
    bool isPossible(vector<int>& nums) 
    {
        int n= nums.size();
        if(n==1)
        {
            return false;
        }
        map<int,int>mp;
        for(int i=0;i<n;i++)
        {
            mp[nums[i]]++;
        }
        for(int it:nums)
        {
            if(mp[it]==0)
            {
                continue;
            }
            int freq = mp[it];
            int curr = it;
            int count=0;
            
            while(mp.count(curr) && mp[curr]>=freq)
            {
                freq = max(freq,mp[curr]);
                mp[curr]--;
                curr++;
                count++;
                
            }
            if(count<3)
            {
                return false;
            }
        }
        return true;
        
        
    }
};