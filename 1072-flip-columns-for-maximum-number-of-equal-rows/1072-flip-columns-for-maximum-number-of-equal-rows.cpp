class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) 
    {
        int n= matrix.size();
        int m = matrix[0].size();
        map<string,int>mp;
        for(int i=0;i<n;i++)
        {
            string s  = "";
            for(int j=1;j<m;j++)
            {
                if(matrix[i][0]==matrix[i][j])
                {
                    s += "T";
                }
                else
                {
                    s += "F";
                }
            }
            mp[s]++;
        }
        int ans =0;
        for(auto it:mp)
        {
            ans = max(ans,it.second);
        }
        return ans;
    }
};