class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {
        int n = s.size();
        unordered_map<char,int>mp;
        int maxx = 0;
        int j=0;
        for(int i=0;i<n;i++)
        {
            if(mp.find(s[i])!=mp.end())
            {
                j = max(mp[s[i]]+1,j);
            }
            mp[s[i]]=i;
            maxx = max(maxx,i-j+1);
        }
        
        return maxx;
    }
};