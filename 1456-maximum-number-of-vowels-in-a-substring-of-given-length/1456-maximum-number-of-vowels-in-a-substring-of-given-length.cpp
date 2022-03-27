class Solution {
public:
    int maxVowels(string s, int k) 
    {
        int n = s.size();
        int cnt=0;
        int ans=0;
        
        for(int i=0;i<k;i++)
        {
            if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u')
            {
                cnt++;
            }
        }
        ans = max(ans,cnt);
        for(int i=k;i<n;i++)
        {
            if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u')
            {
                cnt++;
            }
            if(s[i-k]=='a' || s[i-k]=='e' || s[i-k]=='i' || s[i-k]=='o' || s[i-k]=='u')
            {
                cnt--;
            }
            
            ans = max(ans,cnt);
        }
        
        return ans;
        
    }
};