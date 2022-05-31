// { Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
int dp[1000][1000];
    bool ispallindrome(string s,int i,int j)
    {
        if(i==j)
        {
            return true;
        }
        while(i<=j)
        {
            if(s[i]!=s[j])
            {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    int solve(string s,int i,int j)
    {
        if(i>=j)
        {
            return 0;
        }
        if(ispallindrome(s,i,j))
        {
            return 0;
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        int mn = INT_MAX;
        
        for(int k=i;k<j;k++)
        {
           // int temp = solve(s,i,k)+solve(s,k+1,j)+1;
           int left = -1;
           if(dp[i][k]!=-1)
           {
               left = dp[i][k];
           }
           else
           {
               dp[i][k] = solve(s,i,k);
               left = dp[i][k];
           }
           int right = -1;
           if(dp[k+1][j]!=-1)
           {
               right = dp[k+1][j];
           }
           else
           {
               dp[k+1][j] = solve(s,k+1,j);
               right = dp[k+1][j];
           }
            int temp = 1+left+right;
            mn = min(mn,temp);
        }
        return dp[i][j] = mn;
        
    }
    int palindromicPartition(string str)
    {
        // code here
        memset(dp,-1,sizeof(dp));
        int n = str.size();
        int k = solve(str,0,n-1);
        
        return k;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}  // } Driver Code Ends