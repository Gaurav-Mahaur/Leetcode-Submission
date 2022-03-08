// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    bool fun(int arr[],int n,int target)
    {
       
        if(target==0)
        {
            return true;
        }
         if(n==0)
        {
            return false;
        }
        
        if(arr[n-1]<=target)
        {
            return fun(arr,n-1,target-arr[n-1])||fun(arr,n-1,target);
        }
        return fun(arr,n-1,target);
    }
    int equalPartition(int N, int arr[])
    {
        // code here
        int n = N;
        int sum=0;
        for(int i=0;i<n;i++)
        {
            sum += arr[i];
        }
        if(sum%2==1)
        {
            return 0;
        }
        
        int s = sum/2;
        
        return fun(arr,n,s);
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}  // } Driver Code Ends