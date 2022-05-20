class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) 
    {
        int n = mat.size();
        int m = mat[0].size();
        
        map<int,vector<int>>mp;
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                mp[i+j].push_back(mat[j][i]);
            }
        }
        vector<int>ans;
        int k=0;
        for(auto it:mp)
        {
            if(k%2==0)
            {
                vector<int>t = it.second;
                for(int i=0;i<t.size();i++)
                {
                    ans.push_back(t[i]);
                }
            }
            else
            {
                vector<int>t = it.second;
                reverse(t.begin(),t.end());
                for(int i=0;i<t.size();i++)
                {
                    ans.push_back(t[i]);
                }
            }
            k++;
        }
        return ans;
        
    }
};