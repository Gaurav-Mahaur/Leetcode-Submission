class Solution {
public:
    bool isvalid(int x,int y,vector<vector<int> >&grid,vector<vector<int> >&vis)
    {
        int n = grid.size();
        int m= grid[0].size();
        if(x<0||y<0||x>=n||y>=m)
        {
            return false;
        }
        return true;
    }
    void dfs(int x,int y,vector<vector<int> >grid,vector<vector<int> >&vis,int &area)
    {
        vis[x][y]=1;
        
        int dx[] = {-1,0,1,0};
        int dy[] = {0,1,0,-1};
        
        for(int i=0;i<4;i++)
        {
            int nx = x+dx[i];
            int ny = y+dy[i];
               
            if(isvalid(nx,ny,grid,vis) && vis[nx][ny]==0 && grid[nx][ny]==1)
            {
                area++;
                dfs(nx,ny,grid,vis,area);
            }
        }
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) 
    {
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int> >vis(n,vector<int>(m,0));
        int ans =0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                int area =1;
                if(vis[i][j]==0 && grid[i][j]==1)
                {
                    dfs(i,j,grid,vis,area);
                    ans= max(ans,area);
                }
            }
        }
        return ans;
    }
};