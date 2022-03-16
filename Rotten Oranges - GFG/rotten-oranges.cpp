// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) 
    {
        int n = grid.size();
        int m = grid[0].size();
        
        queue<pair<int,int>>q;
        int fresh=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                {
                    fresh++;
                }
                if(grid[i][j]==2)
                {
                    q.push({i,j});
                }
            }
        }
        if(fresh==0)
        {
            return 0;
        }
        int tot=-1;
        int dx[] = {-1,0,1,0};
        int dy[] = {0,1,0,-1};
        while(!q.empty())
        {
            int sz = q.size();
            tot++;
            for(int i=0;i<sz;i++)
            {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                for(int j=0;j<4;j++)
                {
                    int newx = x+dx[j];
                    int newy = y+dy[j];
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
           return tot;
       }
       return -1;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends