class Solution {
public:
    bool isvalid(int x,int y,vector<vector<int>>&vis,int n,int m)
    {
        if(x<0 ||y<0 || x>=n || y>=m || vis[x][y]==1)
            return false;
        return true;
        
    }
    void dfs(int x,int y,vector<vector<int>> &grid,vector<vector<int>>&vis ,int clr,int newcolor,int n,int m)
    {
        if(x<0 || y<0 || x>=n || y>=m || grid[x][y]!=clr)return;
        
        vis[x][y]=1;
        grid[x][y] = newcolor;
        
        int dx[] = {-1,0,1,0};
        int dy[] = {0,1,0,-1};
        
        for(int i=0;i<4;i++)
        {
            int newx = x+dx[i];
            int newy = y+dy[i];
            if(isvalid(newx,newy,vis,n,m) && abs(grid[newx][newy])==clr)
            {
                dfs(newx,newy,grid,vis,clr,newcolor,n,m);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) 
    {
        int n = image.size();
        int m = image[0].size();
        int clr = image[sr][sc];
        vector<vector<int> >vis(n,vector<int>(m,0));
        dfs(sr,sc,image,vis,clr,newColor,n,m);
       
        return image;
        
    }
};