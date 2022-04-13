class Solution {
public:
    int subarraylessthank(vector<int>&nums,int k)
    {
        int n = nums.size();
        int m = *max_element(nums.begin(),nums.end());
        if(k==0)
        {
            return 0;
        }
        vector<int>fr(m+1,0);
        int count=0;
        int tot=0;
        int j=0;
        for(int i=0;i<n;i++)
        {
            if(fr[nums[i]]==0)
            {
                count++;
            }
            fr[nums[i]]++;
            
            if(count<=k)
            {
                tot += (i-j+1);
            }
            else
            {
                while(count>k)
                {
                    fr[nums[j]]--;
                    if(fr[nums[j]]==0)
                    {
                        count--;
                    }
                    j++;
                }
                tot += (i-j+1);
            }
        }
        
        return tot;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) 
    {
        int n = nums.size();
        
        int k1 = subarraylessthank(nums,k);
        int k2 = subarraylessthank(nums,k-1);
        
        return k1-k2;
        
        
    }
};