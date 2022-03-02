class Solution {
public:
    
    bool isSubsequence(string s, string t) 
    {
        int n = s.size();
        int m = t.size();
        
        int dp[n+1][m+1];
        for(int i=0;i<=m;i++)
        {
            dp[0][i]=0;
        }
        for(int i=0;i<=n;i++)
        {
            dp[i][0]=0;
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(s[i-1]==t[j-1])
                {
                    dp[i][j] = 1+dp[i-1][j-1];
                }
                else
                {
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        int k = dp[n][m];
        if(k==s.size())
        {
            return true;
        }
        return false;
//         string s1 = "";
        
//         int i=n;
//         int j =m;
//         while(i>0&&j>0)
//         {
//             if(s[i-1]==t[j-1])
//             {
//                 s1.push_back(s[i-1]);
//                 i--;
//                 j--;
//             }
//             else
//             {
//                 if(dp[i][j-1]>dp[i-1][j])
//                 {
//                     j--;
//                 }
//                 else
//                 {
//                     i--;
//                 }
//             }
//         }
//         reverse(s1.begin(),s1.end());
        
//         if(s1==s)
//         {
//             return true;
//         }
//         else
//         {
//             return false;
//         }
    }
};