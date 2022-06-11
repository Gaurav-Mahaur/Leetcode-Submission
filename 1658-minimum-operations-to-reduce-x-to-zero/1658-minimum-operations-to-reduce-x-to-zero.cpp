class Solution {
public:
    int minOperations(vector<int>& nums, int x)
    {
        int n = nums.size();
        int sum=0;
        for(int i=0;i<n;i++)
        {
            sum += nums[i];
        }
       // cout<<sum<<endl;
        if(sum==x)
        {
            return n;
        }
        sum -= x;
        
        int currsum =0;
        map<int,int>mp;
        int ans = INT_MIN;
        for(int i=0;i<n;i++)
        {
            currsum += nums[i];
            if(currsum==sum)
            {
                ans = i+1;
            }
            if(mp.find(currsum-sum)!=mp.end())
            {
                ans = max(ans,i-mp[currsum-sum]);
            }
            //else
            
                mp[currsum] = i;
            
        }
        if(ans==INT_MIN)
        {
            return -1;
        }
        return n-ans;
    }
};