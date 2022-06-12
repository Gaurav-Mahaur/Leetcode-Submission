class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) 
    {
        int n = nums.size();
        
        unordered_map<int,int>mp;
        vector<int>pref(n,0);;
        for(int i=0;i<n;i++)
        {
            if(i==0)
            {
                pref[i]=nums[i];
            }
            else
            {
                pref[i] = pref[i-1]+nums[i];
            }
        }
        int j=0;
        int currsum=0;
        int ans =0;
        for(int i=0;i<n;i++)
        {
            if(mp.find(nums[i])!=mp.end())
            {
                if(mp[nums[i]]>=j)
                {
                    
                    if(j==0)
                    {
                        currsum -= pref[mp[nums[i]]];
                    }
                    else
                    {
                        currsum -= pref[mp[nums[i]]]-pref[j-1];
                    }
                    j = mp[nums[i]]+1;
                    
                }
                
                
            }
            currsum += nums[i];
            mp[nums[i]]=i;
            ans = max(ans,currsum);
        }
        return ans;
    }
};