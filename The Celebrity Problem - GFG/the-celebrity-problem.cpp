// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        // code here 
       // int n= M.size();
        stack<int>st;
        for(int i=0;i<n;i++)
        {
            st.push(i);
        }
        while(st.size()>1)
        {
            int a = st.top();st.pop();
            int b = st.top();st.pop();
            if(M[a][b]==1)
            {
                st.push(b);
            }
           else
           {
               st.push(a);
           }
        }
        int pot = st.top();
        
        bool rowcheck=false;
        int zerocnt=0;
        for(int i=0;i<n;i++)
        {
            if(M[pot][i]==0)
            {
                zerocnt++;
            }
        }
        if(zerocnt==n)
        {
            rowcheck=true;
        }
       else
       {
           return -1;
       }
        
        bool colcheck = false;
        int onecnt=0;
        for(int i=0;i<n;i++)
        {
            if(M[i][pot]==1)
            {
                onecnt++;
            }
        }
        if(onecnt == n-1)
        {
            colcheck=true;
        }
        else
        {
            return -1;
        }
        if(colcheck && rowcheck)
        {
            return pot;
        }
        //return -1;
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
        cin>>n;
        vector<vector<int> > M( n , vector<int> (n, 0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>M[i][j];
            }
        }
        Solution ob;
        cout<<ob.celebrity(M,n)<<endl;

    }
}
  // } Driver Code Ends