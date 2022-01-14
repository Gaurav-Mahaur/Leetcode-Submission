class Solution {
public:
    void helping(int idx,vector<int>&a,int n,vector<int>&v,vector<vector<int> >&res,int k)
    {
        if(idx==n)
        {
            if(v.size()==k)
            {
                res.push_back(v);
            }
            return;
        }
        v.push_back(a[idx]);
        helping(idx+1,a,n,v,res,k);
        v.pop_back();
        helping(idx+1,a,n,v,res,k);
    }
    vector<vector<int>> combine(int n, int k) 
    {
        vector<vector<int> > res;
        vector<int>v;
        vector<int>a(n);
        for(int i=0;i<n;i++)
        {
            a[i] = i+1;
        }
        
        helping(0,a,n,v,res,k);
        
        return res;
        
        
    }
};