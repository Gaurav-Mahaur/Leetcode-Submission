// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
  public:
    // arr[] : the input array
    // N : size of the array arr[]
    
    //Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int arr[], int N)
    {
      //Your code here
      int n = N;
      set<int>st;
      for(int i=0;i<n;i++)
      {
          st.insert(arr[i]);
      }
      int maxx = INT_MIN;
      for(int i=0;i<n;i++)
      {
          if(st.count(arr[i]-1))
          {
              continue;
          }
          int j=1;
          while(st.count(arr[i]+j))
          {
              j++;
          }
          maxx = max(maxx,j);
      }
      return maxx;
     
    }
};

// { Driver Code Starts.
 
// Driver program
int main()
{
 int  t,n,i,a[100001];
 cin>>t;
 while(t--)
 {
  cin>>n;
  for(i=0;i<n;i++)
  cin>>a[i];
  Solution obj;
  cout<<obj.findLongestConseqSubseq(a, n)<<endl;
 }
      
    return 0;
}  // } Driver Code Ends