class Solution {
public:
    int countHomogenous(string s) 
    {
        long long int n = s.size();
        int ans=0;
        long long int l=1;
        for(int i=0;i<n-1;i++)
        {
            if(s[i]!=s[i+1])
            {
                ans += ((l*(l+1))/2)%1000000007;
                ans = ans%1000000007;
                l=1;
            }
            else
            {
                l++;
            }
        }
        ans += ((l*(l+1))/2)%1000000007;
        
        return ans;
        
    }
};