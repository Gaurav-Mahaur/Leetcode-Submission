class Solution {
public:
    
    int nthUglyNumber(int n) 
    {
        if(n==1)
        {
            return 1;
        }
        vector<int>dp = {1};
        //dp.push_back(1);
        int two=0;
        int three=0;
        int five=0;
        for(int i=0;i<n-1;i++)
        {
            int temp = min(min(2*dp[two],3*dp[three]),5*dp[five]);
            
            dp.push_back(temp);
            
            if(temp==2*dp[two])
            {
                ++two;
            }
            if(temp==3*dp[three])
            {
                ++three;
            }
            if(temp==5*dp[five])
            {
                ++five;
            }
        }
       // cout<<dp.size();
        for(auto it:dp)
        {
            cout<<it<<" ";
        }
        return dp.back();
    }
};