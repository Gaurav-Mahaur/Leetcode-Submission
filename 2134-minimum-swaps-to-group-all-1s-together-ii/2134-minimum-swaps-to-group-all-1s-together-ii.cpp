class Solution {
public:
    int minSwaps(vector<int>& nums) 
    {
        int n= nums.size();
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            if(nums[i]==1)
            {
                cnt++;
            }
        }
        if(cnt==1)
        {
            return 0;
        }
       for(int i=0;i<n;i++)
        {
            nums.push_back(nums[i]);
        }
        int zerocnt=0;
        for(int i=0;i<cnt;i++)
        {
            if(nums[i]==0)
            {
                zerocnt++;
            }
        }
        int ans = INT_MAX;
        
        if(zerocnt==0)
        {
            return 0;
        }
        
        for(int i=cnt;i<nums.size();i++)
        {
            ans = min(ans,zerocnt);
            if(nums[i]==0)
            {
                zerocnt++;
            }
            if(nums[i-cnt]==0)
            {
                zerocnt--;
            }
        }
        return ans;
        
        
    }
};