class Solution {
public:
    bool isvalid(int x,int y,vector<vector<int> >&grid,vector<vector<int> >&vis)
    {
        int n = grid.size();
        int m = grid[0].size();
        if(x<0||y<0||x>=n||y>=m)
        {
            return false;
        }
        if(vis[x][y]==1 || grid[x][y]==0)
        {
            return false;
        }
        return true;
    }
    void dfs(int x,int y, vector<vector<int>>&grid2,vector<vector<int> >&grid1,vector<vector<int>>&vis,int &flag)
    {
        vis[x][y]=1;
        
        int dx[] = {-1,0,1,0};
        int dy[] = {0,1,0,-1};
        if(grid1[x][y]==0 && grid2[x][y]==1)
        {
            flag=0;
        }
        for(int i=0;i<4;i++)
        {
            int nx = x+dx[i];
            int ny = y+dy[i];
            if(isvalid(nx,ny,grid2,vis))
            {
                if(grid2[nx][ny]==1 && grid1[nx][ny]==0)
                {
                    flag=0;
                }
                dfs(nx,ny,grid2,grid1,vis,flag);
            }
        }
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) 
    {
        int n = grid1.size();
        int m = grid1[0].size();
        vector<vector<int> >vis(n,vector<int>(m,0));
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                
                if(!vis[i][j] && grid2[i][j]==1)
                {
                    int flag=1;
                    dfs(i,j,grid2,grid1,vis,flag);
                    if(flag==1)
                    {
                        cnt++;
                    }
                }
            }
        }
        return cnt;
        
    }
};