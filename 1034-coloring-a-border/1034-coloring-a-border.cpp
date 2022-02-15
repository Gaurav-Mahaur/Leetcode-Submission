class Solution {
public:
    
    void dfs(int x,int y,vector<vector<int>>&grid,int val,int n,int m)
    {
        grid[x][y]=-val;
        int count=0;
        int drx[] = {-1,0,1,0};
        int dry[] = {0,1,0,-1};
        for(int i=0;i<4;i++)
        {
            int newx = x+drx[i];
            int newy = y+dry[i];
            if(newx<0 || newy<0 ||newx>=n || newy>=m || abs(grid[newx][newy])!=(val))
            {
                continue;
            }
            
            count++;
            if(grid[newx][newy]==val)
            {
                dfs(newx,newy,grid,val,n,m);
            }
            
            
        }
        if(count==4)
        {
            grid[x][y]=val;
        }
    }
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) 
    {
        int n = grid.size();
        int m = grid[0].size();
        int val = grid[row][col];
        dfs(row,col,grid,val,n,m);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]<0)
                {
                    grid[i][j]=color;
                }
            }
        }
        return grid;
    }
};