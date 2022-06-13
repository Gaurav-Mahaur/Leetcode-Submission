class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) 
    {
        int n = grid.size();
        vector<int>row;
        vector<int>col;
        for(int i=0;i<n;i++)
        {
            vector<int>t = grid[i];
            row.push_back(*max_element(t.begin(),t.end()));
        }
        for(int i=0;i<n;i++)
        {
            int maxx = INT_MIN;
            for(int j=0;j<n;j++)
            {
                maxx = max(maxx,grid[j][i]);
            }
            col.push_back(maxx);
        }
        int s=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                int inc = min(row[i],col[j]);
                s += inc-grid[i][j];
            }
        }
        return s;
        
    }
};