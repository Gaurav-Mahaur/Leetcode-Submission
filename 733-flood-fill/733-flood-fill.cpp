class Solution {
public:
    bool isvalid(int x,int y,int n,int m,vector<vector<int>>&vis)
    {
        if(x<0 || y<0 || x>=n || y>=m || vis[x][y]==1)
        {
            return false;
        }
        return true;
    }
    void fun(int x,int y,vector<vector<int> >&grid,vector<vector<int>>&vis,int clr,int newcolor,int n,int m)
    {
        if(x<0 || y<0 || x>=n || y>=m || grid[x][y]!=clr)
        {
            return;
        }
        vis[x][y]=1;
        grid[x][y] = newcolor;
        
        int dx[] = {-1,0,1,0};
        int dy[] = {0,1,0,-1};
        
        for(int i=0;i<4;i++)
        {
            if(isvalid(x+dx[i],y+dy[i],n,m,vis) && grid[x+dx[i]][y+dy[i]]==clr)
            {
                int newx = x+dx[i];
                int newy = y+dy[i];
                fun(newx,newy,grid,vis,clr,newcolor,n,m);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) 
    {
        int n = image.size();
        int m = image[0].size();
        int clr = image[sr][sc];
        
        vector<vector<int> > vis(n,vector<int>(m,0));
        fun(sr,sc,image,vis,clr,newColor,n,m);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(image[i][j]<0)
                {
                    image[i][j]=newColor;
                }
            }
        }
        
        return image;
    }
};