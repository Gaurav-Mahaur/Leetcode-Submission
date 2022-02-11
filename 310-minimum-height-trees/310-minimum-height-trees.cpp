class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) 
    {
        vector<int>adj[n];
        vector<int>degree(n,0);
        
        if(n==1)
        {
            return {0};
        }
        for(int i=0;i<edges.size();i++)
        {
            int x = edges[i][0];
            int y = edges[i][1];
            adj[x].push_back(y);
            adj[y].push_back(x);
            degree[x]++;degree[y]++;
        }
        queue<int>q;
        for(int i=0;i<n;i++)
        {
            if(degree[i]==1)
            {
                q.push(i);
            }
        }
        vector<int>ans;
        
        while(!q.empty())
        {
            int n1 = q.size();
            ans.clear();
            for(int i=0;i<n1;i++)
            {
                int node = q.front();
                q.pop();
                
                ans.push_back(node);
                for(auto it:adj[node])
                {
                    degree[it]--;
                    if(degree[it]==1)
                    {
                        q.push(it);
                    }
                }
                
            }
        }
        return ans;
        
        
    }
};