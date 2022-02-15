class Solution {
public:
    bool isvalid(int x,int y,int n,int m)
    {
        if(x<0||y<0||x>=n||y>=m)
            return false;
        return true;
    }
    void dfs(int x,int y,int &area,vector<vector<int>>&grid,int n,int m)
    {
        if(!isvalid(x,y,n,m))
        {
            return;
        }
        if(grid[x][y]==0)
        {
            return;
        }
        area++;
        grid[x][y]=0;
        
        dfs(x+1,y,area,grid,n,m);
        dfs(x,y+1,area,grid,n,m);
        dfs(x-1,y,area,grid,n,m);
        dfs(x,y-1,area,grid,n,m);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) 
    {
        int n = grid.size();
        int m = grid[0].size();
        int maxx =0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                {
                    int area=0;
                    dfs(i,j,area,grid,n,m);
                    maxx = max(maxx,area);
                }
            }
        }
        return maxx;
        
    }
};