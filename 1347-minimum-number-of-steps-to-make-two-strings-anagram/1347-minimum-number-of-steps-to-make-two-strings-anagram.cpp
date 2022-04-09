class Solution {
public:
    int minSteps(string s, string t) 
    {
        int n =s.size();
        vector<int>a(26,0);
        vector<int>b(26,0);
        for(int i=0;i<n;i++)
        {
            a[s[i]-'a']++;
            b[t[i]-'a']++;
        }
        int cnt=0;
        for(int i=0;i<26;i++)
        {
            if(b[i]>a[i])
            {
                cnt += b[i]-a[i];
            }
        }
        return cnt;
        
    }
};