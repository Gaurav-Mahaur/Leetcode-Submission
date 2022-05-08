class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {
        int n = s.size();
        unordered_map<int,int>mp;
        int j=0;
        int maxx =0;
        for(int i=0;i<n;i++)
        {
            if(mp.find(s[i])!=mp.end())
            {
                j = max(j,mp[s[i]]+1);
            }
            mp[s[i]]=i;
            maxx = max(maxx,i-j+1);
            
        }
        return maxx;
    }
};