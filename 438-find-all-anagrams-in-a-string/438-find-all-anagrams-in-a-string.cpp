class Solution {
public:
    vector<int> findAnagrams(string s, string p) 
    {
        int n1 = s.size();
        int n2 = p.size();
        vector<int>freq_s(26,0);
        vector<int>freq_p(26,0);
        vector<int>ans;
        if(n1<n2)
        {
            return {};
        }
        for(int i=0;i<n2;i++)
        {
            freq_s[s[i]-'a']++;
            freq_p[p[i]-'a']++;
        }
        if(freq_s==freq_p)
        {
            ans.push_back(0);
        }
        for(int i=n2;i<n1;i++)
        {
            freq_s[s[i-n2]-'a']--;
            freq_s[s[i]-'a']++;
            
            if(freq_s==freq_p)
            {
                ans.push_back(i-n2+1);
            }
        }
        
        return ans;
        
    }
};