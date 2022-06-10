class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {
        int n = s.size();
        unordered_map<char,int>mp;
        int j=0;
        int ans = 0;
        int len = 0;
        for(int i=0;i<n;i++)
        {
            if(mp.find(s[i])!=mp.end())
            {
                j = max(j,mp[s[i]]+1);
                
            }
            mp[s[i]]=i;
            ans = max(i-j+1,ans);
            
        }
        return ans;
        
    }
};