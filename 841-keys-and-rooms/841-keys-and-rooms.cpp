class Solution {
public:
    void dfs(int src,vector<vector<int>>rooms,vector<int>&vis)
    {
        vis[src]=1;
        
        for(auto it:rooms[src])
        {
            if(!vis[it])
            {
                dfs(it,rooms,vis);
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) 
    {
        int n = rooms.size();
        vector<int>vis(n+1,0);
        dfs(0,rooms,vis);
        
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                return false;
            }
        }
       return true;
        
    }
};