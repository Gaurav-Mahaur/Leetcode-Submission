// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
//User function template for C++

class Solution{   
public:
    bool issubset(vector<int>&arr,int n,int sum,vector<int>&dp)
    {
        if(sum==0)
        {
            return true;
        }
        if(n==0)
        {
            return false;
        }
        
       // if(dp[])
        if(arr[n-1]<=sum)
        {
            return issubset(arr,n-1,sum-arr[n-1],dp)||issubset(arr,n-1,sum,dp);
        }
        return issubset(arr,n-1,sum,dp);
        
    }
    bool isSubsetSum(vector<int>arr, int sum)
    {
        int n = arr.size();
       vector<vector<int> > dp(n+1,vector<int>(sum+1));
       for(int i=0;i<=sum;i++)
       {
           dp[0][i] =0;
       }
       for(int i=0;i<=n;i++)
       {
           dp[i][0]=1;
       }
       for(int i=1;i<=n;i++)
       {
           for(int j=1;j<=sum;j++)
           {
               if(arr[i-1]<=j)
               {
                   dp[i][j] = dp[i-1][j-arr[i-1]]||dp[i-1][j];
               }
               else
               {
                   dp[i][j] = dp[i-1][j];
               }
           }
       }
       int k = dp[n][sum];
        return k;
         
        
    }
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 
  // } Driver Code Ends