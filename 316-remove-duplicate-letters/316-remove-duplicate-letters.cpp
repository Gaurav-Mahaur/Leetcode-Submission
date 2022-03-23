class Solution {
public:
    string removeDuplicateLetters(string s) 
    {
        int n = s.size();
        vector<int>last(26,0);
        vector<bool>vis(26,false);
        
        for(int i= 0;i<n;i++)
        {
            last[s[i]-'a'] = i;
        }
        string ans="";
        for(int i=0;i<n;i++)
        {
            if(vis[s[i]-'a']==true)
            {
                continue;
            }
            while(!ans.empty() && ans.back()>s[i] && last[ans.back()-'a']>i)
            {
                vis[ans.back()-'a'] = false;
                ans.pop_back();
                
            }
            ans.push_back(s[i]);
            vis[s[i]-'a'] = true;
        }
        return ans;
    }
};