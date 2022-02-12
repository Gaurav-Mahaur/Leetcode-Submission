class Solution {
public:
    bool isAnagram(string s, string t) 
    {
        int s_len =s.size();
        int t_len = t.size();
        vector<int>s_freq(26,0);
        vector<int>t_freq(26,0);
        for(int i=0;i<s_len;i++)
        {
            s_freq[s[i]-'a']++;
        }
        for(int i=0;i<t_len;i++)
        {
            t_freq[t[i]-'a']++;
        }
        if(s_freq==t_freq)
        {
            return true;
        }
        return false;
        
        
    }
};