class Solution {
public:
    void helping(int idx,vector<int>arr,vector<int>&temp,int target,int k,set<vector<int> >&res,int &currsum)
    {
        if(idx==9)
        {
            if(currsum==target && temp.size()==k)
            {
                res.insert(temp);
            }
            return;
        }
        currsum += arr[idx];
        temp.push_back(arr[idx]);
        helping(idx+1,arr,temp,target,k,res,currsum);
        currsum -= arr[idx];
        temp.pop_back();
        
        helping(idx+1,arr,temp,target,k,res,currsum);
    }
    vector<vector<int>> combinationSum3(int k, int n) 
    {
        vector<int>arr;
        for(int i=0;i<9;i++)
        {
            arr.push_back(i+1);
        }
        set<vector<int> >res;
        vector<int>tmp;
        int sum=0;
        helping(0,arr,tmp,n,k,res,sum);
        vector<vector<int> >ans;
        for(auto it:res)
        {
            ans.push_back(it);
        }
        
        return ans;
    }
};