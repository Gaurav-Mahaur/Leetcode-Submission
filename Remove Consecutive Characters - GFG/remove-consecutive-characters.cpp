// { Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 


 // } Driver Code Ends

class Solution{
    public:
    string removeConsecutiveCharacter(string S)
    {
        // code here.
        string ans ="";
        int n = S.size();
        stack<char>st;
        for(int i=0;i<S.size();i++)
        {
            if(st.empty())
            {
                st.push(S[i]);
            }
            else if(!st.empty() && S[i]==st.top())
            {
                continue;
            }
            else
            {
                if(!st.empty() && S[i]!=st.top())
                {
                    st.push(S[i]);
                }
            }
        }
       while(!st.empty())
       {
           ans += st.top();
           st.pop();
       }
       reverse(ans.begin(),ans.end());
        return ans;
    }
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.removeConsecutiveCharacter(s)<<endl;
    }
} 



  // } Driver Code Ends