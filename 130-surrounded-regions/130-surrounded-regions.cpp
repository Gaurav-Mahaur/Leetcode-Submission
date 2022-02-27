class Solution {
public:
    bool isvalid(int x,int y,int n,int m)
    {
        if(x<0 || y<0 || x>=n || y>=m)
        {
            return false;
        }
        return true;
    }
    bool isborder(int x,int y,int n,int m)
    {
        if(x==0 || y==0 || x==n-1 || y==m-1)
        {
            return false;
        }
        return true;
    }
    void dfs(int x,int y,vector<vector<char>>&board,int n,int m)
    {
        if(x<0 || y<0 || x>=n || y>=m)
        {
            return;
        }
        
        if(board[x][y]!='O')return;
        
        board[x][y]='A';
        
        int dx[] = {-1,0,1,0};
        int dy[] = {0,1,0,-1};
        
        for(int i=0;i<4;i++)
        {
            if(isvalid(x+dx[i],y+dy[i],n,m) && board[x+dx[i]][y+dy[i]]=='O' && isborder(x+dx[i],y+dy[i],n,m))
            {
                int newx = x+dx[i];
                int newy = y+dy[i];
                dfs(newx,newy,board,n,m);
            }
        }
    }
    void solve(vector<vector<char>>& board) 
    {
        int n = board.size();
        int m=board[0].size();
        
       for(int i=0;i<n;i++)
       {
            dfs(i,0,board,n,m);
            dfs(i,m-1,board,n,m);
       }
        for(int i=0;i<m;i++)
       {
            dfs(0,i,board,n,m);
            dfs(n-1,i,board,n,m);
       }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(board[i][j]=='A')
                {
                    board[i][j] = 'O'; 
                }
                else if(board[i][j]=='O')
                {
                    board[i][j]='X';
                }
            }
        }
    
        
    }
};