class Solution {
public:
    int majorityElement(vector<int>& nums)
    {
        int n = nums.size();
        int cnt=1;
        if(n==1)
        {
            return nums[0];
        }
        int index=0;
        for(int i=1;i<n;i++)
        {
            if(nums[i]==nums[index])
            {
                cnt++;
            }
            else
            {
                cnt--;
            }
            
            if(cnt==0)
            {
                index = i;
                cnt=1;
            }
        }
        int count=0;
        int val = nums[index];
        cout<<val<<endl;
        for(int i=0;i<n;i++)
        {
            if(nums[i]==val)
            {
                count++;
            }
        }
        if(count>n/2)
        {
            return val;
        }
        return 0;
    }
};