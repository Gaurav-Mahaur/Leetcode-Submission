class Solution {
public:
    int minSteps(string s, string t) 
    {
        int n = s.size();
        int m = t.size();
        vector<int>a(26,0);
        vector<int>b(26,0);
        for(int i=0;i<n;i++)
        {
            a[s[i]-'a']++;
        }
        for(int i=0;i<m;i++)
        {
            b[t[i]-'a']++;
        }
        int cnt=0;
        for(int i=0;i<26;i++)
        {
            if(a[i]!=b[i])
            {
                cnt += abs(a[i]-b[i]);
            }
        }
        return cnt;
        
        
    }
};