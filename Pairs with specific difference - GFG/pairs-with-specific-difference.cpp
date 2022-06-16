// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution{
    public:
    int maxSumPairWithDifferenceLessThanK(int arr[], int N, int K)
    {
        // Your code goes here   
        int n = N;
        int k = K;
        int sum=0;
        sort(arr,arr+n);
        int r=n-1;
        
        while(r>=0)
        {
            if(r>0)
            {
                if(arr[r]-arr[r-1]<k)
                {
                    sum += arr[r]+arr[r-1];
                    r-=2;
                }
                else
                {
                    r--;
                }
            }
            else
            {
                r--;
            }
            
        }
        return sum;
    }
};

// { Driver Code Starts.
int main() {
	int t;
	cin>>t;
	while(t--)
	{
		int N;
		cin>>N;
		int arr[N];
		for(int i=0;i<N;i++)
		cin>>arr[i];

		int K;
		cin>>K;
        Solution ob;
		cout<<ob.maxSumPairWithDifferenceLessThanK(arr,N,K)<<endl;
	}
	return 0;
}
  // } Driver Code Ends