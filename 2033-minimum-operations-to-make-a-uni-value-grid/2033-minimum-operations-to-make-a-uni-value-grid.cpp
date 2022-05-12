class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) 
    {
        int n = grid.size();
        int m = grid[0].size();
        
        set<int>st;
        vector<int>t;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                t.push_back(grid[i][j]);
                st.insert((grid[i][j])%x);
            }
        }
        if(st.size()>1)
        {
            return -1;
        }
         sort(t.begin(),t.end());
         int tot = n*m;
         int mid = t[tot/2];
         int sum=0;
        for(int i=0;i<t.size();i++)
        {
            sum += (abs(mid-t[i]))/x;
        }
        return sum;
        
        
    }
};