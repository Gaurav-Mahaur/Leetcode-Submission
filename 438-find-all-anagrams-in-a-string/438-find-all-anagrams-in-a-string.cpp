class Solution {
public:
    vector<int> findAnagrams(string s, string p)
    {
        int n1 = s.size();
        int n2 = p.size();
        vector<int>ans;
        if(n1<n2)
        {
            return {};
        }
        vector<int>v1(26,0);
        vector<int>v2(26,0);
        for(int i=0;i<n2;i++)
        {
            v2[p[i]-'a']++;
             v1[s[i]-'a']++;
        }
        
        if(v1==v2)
        {
           ans.push_back(0); 
        }
        for(int i=n2;i<n1;i++)
        {
            v1[s[i-n2]-'a']--;
            v1[s[i]-'a']++;
            if(v1==v2)
            {
                ans.push_back(i-n2+1);
            }
        }
        return ans;
        
    }
};