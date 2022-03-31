class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums)
    {
        int n = nums.size();
        vector<int>prefix(n);
        vector<int>suffix(n);
        prefix[0] = nums[0];
        suffix[n-1]=nums[n-1];
        for(int i=1;i<n;i++)
        {
            prefix[i] = prefix[i-1]+nums[i];
        }
        for(int i=n-2;i>=0;i--)
        {
            suffix[i] = suffix[i+1]+nums[i];
        }
        
        vector<int>ans;
        
        for(int i=0;i<n;i++)
        {
            int res = nums[i]*(i+1) - prefix[i];
            if(i!=n-1)
            {
                res += suffix[i+1] - (n-i-1)*nums[i];
            }
            
            ans.push_back(res);
        }
       
        
        return ans;
        
    }
};