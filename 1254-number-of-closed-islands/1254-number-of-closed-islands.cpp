class Solution {
public:
    bool isvalid(int x,int y,vector<vector<int>>&grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        if(x<0||y<0||x>=n||y>=m)
        {
            return false;
        }
        if(grid[x][y]==1)
        {
            return false;
        }
        return true;
    }
    void dfs(int x,int y,vector<vector<int>>&grid)
    {
        if(x<0 || y<0 || x>=grid.size() || y>=grid[0].size() || grid[x][y])
            return;
        
        grid[x][y]=1;
        
        int dx[] = {-1,0,1,0};
        int dy[] = {0,1,0,-1};
        
        for(int i=0;i<4;i++)
        {
            int nx = x+dx[i];
            int ny = y+dy[i];
           
            if(isvalid(nx,ny,grid))
            {
                dfs(nx,ny,grid);
            }
        }
    }
    int closedIsland(vector<vector<int>>& grid) 
    {
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int> >vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++)
        {
            dfs(i,0,grid);
            dfs(i,m-1,grid);
        }
        for(int i=0;i<m;i++)
        {
            dfs(0,i,grid);
            dfs(n-1,i,grid);
        }
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==0)
                {
                    dfs(i,j,grid);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};