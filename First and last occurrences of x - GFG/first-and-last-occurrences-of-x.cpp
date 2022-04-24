// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
vector<int> find(int arr[], int n , int x )
{
    // code here
    int l=0;
    int r=n-1;
    int x1 = -1;
    int y1 = -1;
    while(l<=r)
    {
        int m = l+(r-l)/2;
        if(arr[m]==x)
        {
            x1 =m;
            r=m-1;
        }
        else if(arr[m]>x)
        {
            r =m-1;
        }
        else
        {
            l = m+1;
        }
    }
    l=0;
    r=n-1;
    while(l<=r)
    {
        int m = l+(r-l)/2;
        if(arr[m]==x)
        {
            y1 =m;
            l = m+1;
        }
        else if(arr[m]>x)
        {
            r =m-1;
        }
        else
        {
            l = m+1;
        }
    }
    vector<int>ans;
    ans.push_back(x1);
    ans.push_back(y1);
    return ans;
}

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        ans=find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}


  // } Driver Code Ends