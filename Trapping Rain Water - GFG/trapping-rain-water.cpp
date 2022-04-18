// { Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
class Solution{

    // Function to find the trapped water between the blocks.
    public:
    long long trappingWater(int arr[], int n)
    {
        
        // code here
        vector<int>a(n);
        a[0] = arr[0];
        vector<int>b(n);
        b[n-1]=arr[n-1];
        for(int i=1;i<n;i++)
        {
            a[i] = max(a[i-1],arr[i]);
        }
        for(int i=n-2;i>=0;i--)
        {
            b[i] = max(b[i+1],arr[i]);
        }
        long long int sum=0;
        for(int i=0;i<n;i++)
        {
            sum += (min(a[i],b[i])-arr[i]);
        }
        
        return sum;
        
    }
};

// { Driver Code Starts.

int main(){
    
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        
        int a[n];
        
        //adding elements to the array
        for(int i =0;i<n;i++){
            cin >> a[i];            
        }
        Solution obj;
        //calling trappingWater() function
        cout << obj.trappingWater(a, n) << endl;
        
    }
    
    return 0;
}  // } Driver Code Ends