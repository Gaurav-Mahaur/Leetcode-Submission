class Solution {
public:
    int firstpos(vector<int>&nums,int l,int r,int target)
    {
        int k=-1;
        while(l<=r)
        {
            int m = (l+r)/2;
            
            if(nums[m]==target)
            {
                k = m;
                r=m-1;
            }
            else if(nums[m]<target)
            {
                l=m+1;
            }
            else if(nums[m]>target)
            {
                r=m-1;
            }
        }
        return k;
    }
    int lastpos(vector<int>&nums,int l,int r,int target)
    {
        int k  =-1;
        
        while(l<=r)
        {
            int m = (l+r)/2;
            
            if(nums[m]==target)
            {
                k = m;
                l=m+1;
            }
            else if(nums[m]>target)
            {
                r = m-1;
            }
            else if(nums[m]<target)
            {
                l=m+1;
            }
        }
        return k;
    }
    vector<int> searchRange(vector<int>& nums, int target) 
    {
        int n = nums.size();
        int first = firstpos(nums,0,n-1,target);
        int last = lastpos(nums,0,n-1,target);
        vector<int>ans;
        ans.push_back(first);
        ans.push_back(last);
        
        return ans;
        
    }
};