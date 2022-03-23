class Solution {
public:
    bool isvalid(int x,int y,vector<vector<int> >&grid,vector<vector<int>  >&vis,int n,int m)
{
    if(x<0 || y<0 || x>=n || y>=m)
    {
        return false;
    }
    if(grid[x][y]==0 || vis[x][y]==1)
    {
        return false;
    }
    return true;
}
void component(int x,int y,vector<vector<int> >&grid,vector<vector<int>>&vis,int n,int m)
{
    if(x<0 || y<0 || x>=n || y>=m)return;

    vis[x][y]=1;
    queue<pair<int,int> >q;
    q.push({x,y});

    int dx[] = {-1,0,1,0};
    int dy[] = {0,1,0,-1};
    while(!q.empty())
    {
        int currx = q.front().first;
        int curry = q.front().second;
        q.pop();

        for(int i=0;i<4;i++)
        {
            int newx = currx+dx[i];
            int newy = curry+dy[i];
            if(isvalid(newx,newy,grid,vis,n,m))
            {
                q.push({newx,newy});
                vis[newx][newy] = 1;
            }
        }
    }
}
int componentofgrid(vector<vector<int> >&grid,int n,int m)
{
    vector<vector<int>>vis(n,vector<int>(m,0));

    int cnt=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(grid[i][j]==1 && vis[i][j]==0)
            {
                cnt++;
                component(i,j,grid,vis,n,m);
            }
        }
    }
    return cnt;
}
    int minDays(vector<vector<int>>& grid) 
    {
        int n = grid.size();
        int m = grid[0].size();
    
        int tot = componentofgrid(grid,n,m);
        //cout<<componentofgrid(grid,n,m);
        if(tot==0)return 0;
        
        if(tot>1)
        {
            return 0;
        }
        if(n==0)
        {
            return 0;
        }
        int one = 0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
               if(grid[i][j]==1)
               {
                   one++;
               }
            }
        }
        if(tot==1)
        {
            if(one==1)
            {
                return 1;
            }
            if(one==2)
            {
                return 2;
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
               if(grid[i][j]==1)
               {
                   grid[i][j]=0;
                    int cntt = componentofgrid(grid,n,m);
                    if(cntt>1)
                    {
                        return 1;
                    }
                    grid[i][j]=1;
               }
            }
        }
       
        return 2;
        
    }
};