class Solution {
public:
     int dx[4] = {-1,0,1,0};
    int dy[4] = {0,1,0,-1};
    
    static bool isvalid(int x,int y,int n)
    {
        if(x<0||y<0||x>=n||y>=n)
        {
            return false;
        }
        return true;
    }
    void dfs(int x,int y,vector<vector<int>>&grid,vector<vector<int>>&vis,int n,queue<pair<int,int>>&q)
    {
        vis[x][y]=1;
        
       
        
        for(int i=0;i<4;i++)
        {
            int nx = x+dx[i];
            int ny = y+dy[i];
            if(isvalid(nx,ny,n) && grid[nx][ny]==1 && vis[nx][ny]==0)
            {
                q.push({nx,ny});
                dfs(nx,ny,grid,vis,n,q);
                
            }
        }
        
    }
    int shortestBridge(vector<vector<int>>& grid) 
    {
        int n = grid.size();
        queue<pair<int,int>>q;
        vector<vector<int>>vis(n,vector<int>(n,0));
        int flag=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1 && flag==0)
                {
                    q.push({i,j});
                    dfs(i,j,grid,vis,n,q);
                    flag=1;
                }
                
            }
        }
        int lev=0;
        
        while(!q.empty())
        {
            int sz = q.size();
            lev++;
            while(sz--)
            {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                
                for(int i=0;i<4;i++)
                {
                    int nx = x+dx[i];
                    int ny = y+dy[i];
                    if(isvalid(nx,ny,n))
                    {
                        if(grid[nx][ny]==1 && vis[nx][ny]==0)
                        {
                            return lev-1;
                        }
                        else if(vis[nx][ny]==0)
                        {
                            q.push({nx,ny});
                            vis[nx][ny]=1;
                        }
                    }
                }
                
                
            }
        }
        return -1;
        
    }
};