class Solution {
public:
    int lengthOfLIS(vector<int>& nums) 
    {
        vector<int>a;
        set<int>s;
        int n = nums.size();
        for(int i=0;i<n;i++)
        {
            s.insert(nums[i]);
        }
        for(auto it:s)
        {
            a.push_back(it);
        }
        sort(a.begin(),a.end());
        //int n = nums.size();
        int m = a.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1));
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=m;j++)
            {
                if(i==0||j==0)
                {
                    dp[i][j]=0;
                }
            }
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(nums[i-1]==a[j-1])
                {
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else
                {
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        
        int k = dp[n][m];
        return k;
    }
};