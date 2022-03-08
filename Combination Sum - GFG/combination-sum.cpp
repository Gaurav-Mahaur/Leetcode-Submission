// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution {
  public:
    //Function to return a list of indexes denoting the required 
    //combinations whose sum is equal to given number.
    void fun(int idx,vector<int>&a,int n, int target,vector<vector<int>>&ans,vector<int>v)
    {
        if(idx==n)
        {
            if(target==0)
            {
                ans.push_back(v);
            }
            return;
        }
        
        if(a[idx]<=target)
        {
            v.push_back(a[idx]);
            target -= a[idx];
            fun(idx,a,n,target,ans,v);
            target += a[idx];
            v.pop_back();
        }
        fun(idx+1,a,n,target,ans,v);
        
        
    }
    vector<vector<int> > combinationSum(vector<int> &A, int B) 
    {
        
        // Your code here
        int n = A.size();
        vector<vector<int> >ans;
        vector<int>v;
        set<int>s;
        for(int i=0;i<n;i++)
        {
            s.insert(A[i]);
        }
        vector<int>newarr;
        for(auto it:s)
        {
            newarr.push_back(it);
        }
        int n1 = newarr.size();
        fun(0,newarr,n1,B,ans,v);
        return ans;
        
    }
};

// { Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> A;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            A.push_back(x);
        }   
        int sum;
        cin>>sum;
        Solution ob;
        vector<vector<int>> result = ob.combinationSum(A, sum);
   		if(result.size()==0){
   			cout<<"Empty";
   		}
        for(int i=0;i<result.size();i++){
            cout<<'(';
            for(int j=0;j<result[i].size();j++){
                cout<<result[i][j];
                if(j<result[i].size()-1)
                    cout<<" ";
            }
            cout<<")";
        }
        cout<<"\n";
    }
}	  // } Driver Code Ends