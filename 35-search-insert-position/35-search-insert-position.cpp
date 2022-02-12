class Solution {
public:
    int searchInsert(vector<int>& nums, int target)
    {
        int f=0,mid;
        int n=nums.size();
        int l=n-1;
        if(target<nums[0])
            return 0;
        while(f<=l)
        {
            mid=(f+l)/2;
            if(nums[mid]==target)
                return mid;
            else if(nums[mid]<target && (mid==l||nums[mid+1]>target))
                return mid+1;
            else if(nums[mid]<target)
                f=mid+1;
            else
                l=mid-1;
            //cout<<f<<mid<<l<<endl;
        }
        return mid+1;
    
        
    }
};