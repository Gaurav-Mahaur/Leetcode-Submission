class Solution {
public:
    long long subArrayRanges(vector<int>& nums) 
    {
        int n = nums.size();
        long long int sum=0;
        
        for(int i=0;i<n;i++)
        {
            int minn = nums[i];
            int maxx = nums[i];
            for(int j=i+1;j<n;j++)
            {
                minn = min(minn,nums[j]);
                maxx = max(maxx,nums[j]);
                
                sum += (long long int)(maxx-minn);
            }
            
        }
        return sum;
    }
};