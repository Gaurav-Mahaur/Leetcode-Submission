class Solution {
public:
    
    vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries) 
    {
        vector<bool>ans;
        int n = s.size();
        vector<vector<int>> prefix;
        vector<int>temp(26,0);
        prefix.push_back(temp);
        for(int i=0;i<n;i++)
        {
            temp[s[i]-'a']++;
            prefix.push_back(temp);
        }
        for(int i=0;i<queries.size();i++)
        {
            int l = queries[i][0];
            int r = queries[i][1];
            int k = queries[i][2];
            vector<int>sub = prefix[r+1];
            int odd =0;
            int sum = r-l+1;
            for(int j=0;j<26;j++)
            {
                sub[j] = sub[j]-prefix[l][j];
                odd += (sub[j])%2;
            }
            bool t = (odd<=2*k + (sum%2));
            ans.push_back(t);
        }
        return ans;
        
    }
};