// { Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution{
  public:
    vector<vector<string> > Anagrams(vector<string>& string_list) 
    {
        //code here
    
        map<map<char,int>,vector<string>> bigmap;
        for(int i=0;i<string_list.size();i++)
        {
            map<char,int>mp;
            for(int j=0;j<string_list[i].size();j++)
            {
                mp[string_list[i][j]]++;
            }
            bigmap[mp].push_back(string_list[i]);
        }
        vector<vector<string> > ans;
        for(auto it:bigmap)
        {
            ans.push_back(it.second);
        }
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
        int n;
        cin>>n;
        vector<string> string_list(n);
        for (int i = 0; i < n; ++i)
            cin>>string_list[i]; 
        Solution ob;
        vector<vector<string> > result = ob.Anagrams(string_list);
        sort(result.begin(),result.end());
        for (int i = 0; i < result.size(); i++)
        {
            for(int j=0; j < result[i].size(); j++)
            {
                cout<<result[i][j]<<" ";
            }
            cout<<"\n";
        }
    }

    return 0;
}
  // } Driver Code Ends