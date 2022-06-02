class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) 
    {
        int m = rolls.size();
        int tot = (n+m)*mean;
        int s=0;
        for(int i=0;i<m;i++)
        {
            s += rolls[i];
        }
        if(tot<s)
        {
            return {};
        }
        int d = tot-s;
        
        int q = d/n;
        int r = d%n;
        if(q>6)
        {
            return {};
        }
        if(q==6 && r>0)
        {
            return {};
        }
        if(q==0 && r<n)
        {
            return {};
        }
        vector<int>ans(n,q);
        for(int i=0;i<r;i++)
        {
            ans[i] += 1;
        }
        return ans;
        
    }
};