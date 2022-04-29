class Solution {
public:
    void dfs(int src,vector<int>adj[],vector<int>&vis)
    {
        vis[src]=1;
        
        for(auto it:adj[src])
        {
            if(!vis[it])
            {
                dfs(it,adj,vis);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) 
    {
        int n = isConnected.size();
        vector<int>adj[n+1];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i!=j)
                {
                    if(isConnected[i][j]==1)
                    {
                        adj[i+1].push_back(j+1);
                        //adj[j].push_back(i);
                    }
                }
            }
        }
        vector<int>vis(n+1,0);
        int cnt=0;
        for(int i=1;i<=n;i++)
        {
            if(!vis[i])
            {
                dfs(i,adj,vis);
                cnt++;
            }
        }
        return cnt;
        
    }
};