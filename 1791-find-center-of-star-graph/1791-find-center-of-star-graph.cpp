class Solution {
public:
    int findCenter(vector<vector<int>>& edges) 
    {
        int m =edges.size();
        int n = m+1;
        vector<int>adj[n+1];
        for(int i=0;i<m;i++)
        {
            int x = edges[i][0];
            int y = edges[i][1];
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        for(int i=1;i<=n;i++)
        {
            if(adj[i].size()==n-1)
            {
                return i;
            }
        }
        return -1;
        
    }
};