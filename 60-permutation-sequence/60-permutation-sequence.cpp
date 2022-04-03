class Solution {
public:
    string getPermutation(int n, int k) 
    {
        string s = "";
        for(int i=1;i<=n;i++)
        {
            s += to_string(i);
        }
        vector<string> ans;
        do
        {
            ans.push_back(s);
        }while(next_permutation(s.begin(),s.end()));
        
        string res = ans[k-1];
        
        return res;
    }
};