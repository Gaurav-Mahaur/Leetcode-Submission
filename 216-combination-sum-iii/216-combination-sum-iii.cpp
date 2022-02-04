class Solution {
public:
    void helping(int idx,vector<int>&a,int n,int sum,int size,vector<int>&v,set<vector<int> >&res,int s)
    {
        if(idx==n)
        {
            if(s==sum && v.size()==size)
            {
                res.insert(v);
            }
            return;
        }
        v.push_back(a[idx]);
        s += a[idx];
        helping(idx+1,a,n,sum,size,v,res,s);
        s -= a[idx];
        v.pop_back();
        helping(idx+1,a,n,sum,size,v,res,s);
    }
    vector<vector<int>> combinationSum3(int k, int n) 
    {
        vector<int>a(9);
        for(int i=0;i<9;i++)
        {
            a[i]=i+1; 
        }
        int n1 = a.size();
        vector<int>v;
        set<vector<int> >res;
        int sum=n;
        helping(0,a,n1,sum,k,v,res,0);
        vector<vector<int> >ans;
        for(auto it:res)
        {
            ans.push_back(it);
        }
        return ans;
        
    }
};