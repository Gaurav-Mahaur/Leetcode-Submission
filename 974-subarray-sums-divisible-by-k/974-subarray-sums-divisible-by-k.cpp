class Solution {
public:
    
    int subarraysDivByK(vector<int>& nums, int k) 
    {
        int n = nums.size();
        map<int,int>mp;
        int currsum=0;
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            currsum += nums[i];
            if(currsum%k==0)
            {
                cnt++;
            }
           int s= currsum%k;
            if(s<0)
            {
                s =s+k;
            }
            if(mp.find(s)!=mp.end())
            {
                cnt += mp[s];
            }
            mp[s]++;
            
        }
        return cnt;
        
    }
};