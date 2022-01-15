class Solution {
public:
//     void permutation(vector<int>nums,vector<int>&a,vector<vector<int> >&res,vector<int>&vis,int n)
//     {
//         if(a.size()==n)
//         {
//             res.push_back(a);
//             return;
//         }
        
//         for(int i=0;i<n;i++)
//         {
//             if(vis[i]==0)
//             {
//                 vis[i]=1;
//                 a.push_back(nums[i]);
//                 permutation(nums,a,res,vis,n);
//                 vis[i]=0;
//                 a.pop_back();
//             }
//         }
//     }
    void permutation(vector<int>nums,int l,int r,vector<int>&a,vector<vector<int> >&res)
    {
        if(l==r)
        {
            res.push_back(nums);
           // return;
        }
        else
        {
            for(int i=l;i<=r;i++)
            {
                swap(nums[l],nums[i]);
                permutation(nums,l+1,r,a,res);
                swap(nums[l],nums[i]);
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) 
    {
        vector<vector<int> > res;
        vector<int>a;
        int n = nums.size();
       // vector<int>vis(n,0);
        permutation(nums,0,n-1,a,res);
        
            return res;
    }
};