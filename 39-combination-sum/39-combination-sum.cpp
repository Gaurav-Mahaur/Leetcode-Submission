class Solution {
public:
    void combination(int idx,vector<int>candidates,int n,int target,vector<int>&v,
                    vector<vector<int> > &res)
    {
        if(idx==n)
        {
            if(target==0)
            {
                res.push_back(v);
            }
            return;
        }
       
        if(candidates[idx]<=target)
        {
            v.push_back(candidates[idx]);
            combination(idx,candidates,n,target-candidates[idx],v,res);
            //sum -= candidates[idx];
            v.pop_back();
        }
        combination(idx+1,candidates,n,target,v,res);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target)
    {
        vector<vector<int> > res;
        vector<int>v;
        int n = candidates.size();
        combination(0,candidates,n,target,v,res);
        
        return res;
    }
};