class Solution {
public:
    int fun(int idx,vector<int>cost)
    {
        if(idx==0||idx==1)
        {
            return 0;
        }
        int onestep = fun(idx-1,cost)+cost[idx-1];
        int twostep = fun(idx-2,cost)+cost[idx-2];
        
        return min(onestep,twostep);
    }
    int minCostClimbingStairs(vector<int>& cost)
    {
        int n=cost.size();
        int dp[n];
        dp[0]=cost[0];
        dp[1]=cost[1];
        for(int i=2;i<n;i++)
        {
            dp[i]=min(dp[i-2],dp[i-1])+cost[i];
        }
        return min(dp[n-1],dp[n-2]);
        
        
    }
};