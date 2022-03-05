// { Driver Code Starts
//Initial function template for C++

#include<bits/stdc++.h>
using namespace std;
#define ll long long

 // } Driver Code Ends
//User function template for C++

class Solution{
    public:
    //Function to count subarrays with sum equal to 0.
    ll findSubarray(vector<ll> arr, int n )
    {
        //code here
        long long int cnt=0;
        long long int currsum=0;
        unordered_map<long long int,long long int>mp;
        for(int i=0;i<n;i++)
        {
            currsum += arr[i];
            if(mp.find(currsum)!=mp.end())
            {
                cnt += mp[currsum];
            }
            if(currsum==0)
            {
                cnt++;
            }
            mp[currsum]++;
        }
        return cnt;
        
    }
    
};

// { Driver Code Starts.
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n; //input size of array
       
        vector<ll> arr(n,0);
        
        for(int i=0;i<n;i++)
            cin>>arr[i]; //input array elements
        Solution ob;
        cout << ob.findSubarray(arr,n) << "\n";
    }
	return 0;
}  // } Driver Code Ends