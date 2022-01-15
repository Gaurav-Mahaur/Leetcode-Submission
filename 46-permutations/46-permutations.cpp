class Solution {
public:
    void permutation(vector<int>nums,vector<int>&a,vector<vector<int> >&res,vector<int>&vis,int n)
    {
        if(a.size()==n)
        {
            res.push_back(a);
            return;
        }
        
        for(int i=0;i<n;i++)
        {
            if(vis[i]==0)
            {
                vis[i]=1;
                a.push_back(nums[i]);
                permutation(nums,a,res,vis,n);
                vis[i]=0;
                a.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) 
    {
        vector<vector<int> > res;
        vector<int>a;
        int n = nums.size();
        vector<int>vis(n,0);
        permutation(nums,a,res,vis,n);
        
            return res;
    }
};