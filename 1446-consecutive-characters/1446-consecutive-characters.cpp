class Solution {
public:
    int maxPower(string s) 
    {
        int n = s.size();
        int maxx = INT_MIN;
        int l=1;
        if(n==1)
        {
            return 1;
        }
        for(int i=0;i<n-1;i++)
        {
            if(s[i]!=s[i+1])
            {
                maxx= max(maxx,l);
                l=1;
            }
            else
            {
                l++;
            }
        }
        maxx = max(l,maxx);
        return maxx;
    }
};