class Solution {
public:
    int dp[2002][2002];
      bool ispallindrome (string & s, int i, int j){
        while(i<j){
            if(s[i]!=s[j]) return false;
            i++; j--;
        }
        return true;
    }
    
    int solve(string s,int i,int j)
    {
        if(i>=j or ispallindrome(s, i, j)) return 0;
        
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        int mn = INT_MAX;
        for(int k=i;k<j;k++)
        {
            //int temp = fun(s,i,k)+fun(s,k+1,j)+1;
//             int left;
//             if(dp[i][k]!=-1)
//             {
//                 left = dp[i][k];
//             }
//             else
//             {
//                 dp[i][k] = solve(s,i,k);
//                 left = dp[i][k];
//             }
//             int right;
//             if(dp[k+1][j]!=-1)
//             {
//                 right = dp[k+1][j];
//             }
//             else
//             {
//                 dp[k+1][j] = solve(s,k+1,j);
//                 right = dp[k+1][j];
//             }
            
//             int temp = left+right+1;
            if(ispallindrome(s,i,k))
            {
                int temp = solve(s,k+1,j)+1;
            
            mn = min(mn,temp);
            }
        }
        return dp[i][j]= mn;
    }
    int minCut(string s) 
    {
        int n = s.size();
        memset(dp,-1,sizeof(dp));
        int k = solve(s,0,n-1);
        return k;
        
    }
};