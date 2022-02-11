class Solution {
public:
    bool bipartite(int src,vector<int>adj[],vector<int>&color)
    {
        color[src]=1;
        queue<int>q;
        q.push(src);
        
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            
            for(auto it:adj[node])
            {
                if(color[it]==-1)
                {
                   color[it]=1-color[node];
                    q.push(it);
                }
                else if(color[it]==color[node])
                {
                    return false;
                }
            }
        }
        return true;
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) 
    {
        int m = dislikes.size();
        vector<int>adj[n+1];
        for(int i=0;i<m;i++)
        {
            int x = dislikes[i][0];
            int y = dislikes[i][1];
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        vector<int>color(n+1,-1);
        for(int i=1;i<=n;i++)
        {
            if(color[i]==-1)
            {
                if(!bipartite(i,adj,color))
                {
                    return false;
                }
            }
        }
        return true;
        
    }
};