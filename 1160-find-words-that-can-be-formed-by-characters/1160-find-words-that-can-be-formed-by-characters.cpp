class Solution {
public:
    int countCharacters(vector<string>& words, string chars) 
    {
        map<char,int>mp;
        for(int i=0;i<chars.size();i++)
        {
            mp[chars[i]]++;
        }
        int ans=0;
        for(int i=0;i<words.size();i++)
        {
            map<char,int>mp1;
            int flag=0;
            for(int j=0;j<words[i].size();j++)
            {
                mp1[words[i][j]]++;
            }
            for(int j=0;j<words[i].size();j++)
            {
                if(mp1[words[i][j]]>mp[words[i][j]])
                {
                    flag=1;
                    break;
                }
            }
            if(flag==0)
            {
                ans += words[i].size();
            } 
           
        }
        return ans;
    }
};