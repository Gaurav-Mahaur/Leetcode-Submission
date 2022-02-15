class Solution {
public:
    void dfs(int x,int y,vector<vector<int> >&grid,int n,int m)
    {
        if(x<0||y<0||x>=n||y>=m || grid[x][y]==0)return;
        int dx[] = {-1,0,1,0};
        int dy[] = {0,1,0,-1};
        grid[x][y]=0;
        for(int i=0;i<4;i++)
        {
            dfs(x+dx[i],y+dy[i],grid,n,m);
        }
    }
    int numEnclaves(vector<vector<int>>& grid) 
    {
        
        int n = grid.size();
        int m = grid[0].size();
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(i==0||j==0||i==n-1||j==m-1)
                {
                    dfs(i,j,grid,n,m);
                }
            }
        }
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                {
                    cnt++;
                }
            }
        }
        return cnt;
        
    }
};