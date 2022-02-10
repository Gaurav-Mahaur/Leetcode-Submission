class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) 
    {
        int m = edges.size();
        vector<int>adj[n];
        for(int i=0;i<m;i++)
        {
            int x = edges[i][0];
            int y = edges[i][1];
            adj[x].push_back(y);
        }
        vector<int>indegree(n,0);
        for(int i=0;i<n;i++)
        {
            for(auto it:adj[i])
            {
                indegree[it]++;
            }
        }
        vector<int>v;
        for(int i=0;i<n;i++)
        {
            if(indegree[i]==0)
            {
                v.push_back(i);
            }
        }
        return v;
        
    }
};