class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) 
    {
        int n = grid.size();
        int m = grid[0].size();
        
        queue<pair<int,int> >q;
        int fresh=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==2)
                {
                    q.push({i,j});
                }
                if(grid[i][j]==1)
                {
                    fresh++;
                }
            }
        }
        if(fresh==0)
        {
            return 0;
        }
        
        int lev=-1;
        int dx[] = {-1,0,1,0};
        int dy[] = {0,1,0,-1};
        
        while(!q.empty())
        {
            int sz = q.size();
            lev++;
            for(int i=0;i<sz;i++)
            {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                
                for(int i=0;i<4;i++)
                {
                    int newx = x+dx[i];
                    int newy = y+dy[i];
                    if(newx>=0 && newy>=0 && newx<n && newy<m && grid[newx][newy]==1)
                    {
                        q.push({newx,newy});
                        grid[newx][newy]=0;
                        fresh--;
                    }
                }
            }
        }
        if(fresh==0)
        {
            return lev;
        }
        return -1;
    }
    
};