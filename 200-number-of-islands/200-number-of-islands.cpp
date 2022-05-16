class Solution {
public:
    bool isvalid(int i,int j,vector<vector<char> > &grid,vector<vector<int> >&vis)
    {
        int n = grid.size();
        int m = grid[0].size();
        if(i<0||i>=n||j<0||j>=m)
        {
            return false;
        }
        if(vis[i][j]==1 || grid[i][j]=='0')
        {
            return false;
        }
        return true;
    }
    void dfs(int x,int y,vector<vector<char>>&grid,vector<vector<int> > &vis )
    {
        vis[x][y]=1;
        
        int dx[] = {-1,0,1,0};
        int dy[] = {0,1,0,-1};
        
        for(int i=0;i<4;i++)
        {
            if(isvalid(x+dx[i],y+dy[i],grid,vis))
            {
                int newx = x+dx[i];
                int newy = y+dy[i];
                dfs(newx,newy,grid,vis);
            }
            
        }
        return;
    }
    int numIslands(vector<vector<char>>& grid) 
    {
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int> >vis(n,vector<int>(m,0));
        
        int cnt=0;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(!vis[i][j] && grid[i][j]=='1')
                {
                    dfs(i,j,grid,vis);
                    cnt++;
                }
            }
        }
        return cnt;
        
    }
};