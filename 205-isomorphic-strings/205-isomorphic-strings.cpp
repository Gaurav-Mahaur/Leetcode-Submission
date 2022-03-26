class Solution {
public:
    bool isIsomorphic(string s, string t) 
    {
        int n1 = s.size();
        int n2 = t.size();
        if(n1!=n2)
        {
            return false;
        }
        map<char,char>mp;
        map<char,bool>vis;
        
        for(int i=0;i<n1;i++)
        {
            int ch1 = s[i];
            int ch2 = t[i];
            
            if(mp.find(ch1)!=mp.end())
            {
                if(mp[ch1]!=ch2)
                {
                    return false;
                }
            }
            else
            {
                if(vis.find(ch2)!=vis.end())
                {
                    return false;
                }
                else
                {
                    mp[ch1] = ch2;
                    vis[ch2] = true;
                }
            }
        }
        return true;
        
    }
};