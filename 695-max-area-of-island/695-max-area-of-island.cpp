class Solution {
public:
    bool isvalid(int x,int y,int n,int m)
    {
        if(x<0||y<0||x>=n||y>=m)
            return false;
        return true;
    }
    
    
    void dfs(int x,int y,int &area,vector<vector<int>>&grid,int n,int m,vector<vector<int>>&vis)
    {
        vis[x][y]=1;
        int dx[] = {-1,0,1,0};
        int dy[] = {0,1,0,-1};
        
        for(int i=0;i<4;i++)
        {
            if(isvalid(x+dx[i],y+dy[i],n,m) && vis[x+dx[i]][y+dy[i]]==0 && grid[x+dx[i]][y+dy[i]]==1)
            {
                area++;
                dfs(x+dx[i],y+dy[i],area,grid,n,m,vis);
            }
        }
        
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) 
    {
        int n = grid.size();
        int m = grid[0].size();
        int maxx =0;
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(vis[i][j]==0 && grid[i][j]==1)
                {
                    int area=1;
                    dfs(i,j,area,grid,n,m,vis);
                    maxx = max(maxx,area);
                }
            }
        }
        return maxx;
        
    }
};