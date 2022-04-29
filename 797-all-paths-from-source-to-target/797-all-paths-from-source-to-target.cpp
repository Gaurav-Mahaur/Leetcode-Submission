class Solution {
public:
    void fun(int s,int t,vector<vector<int> >graph,vector<int>&vis,vector<int>&path,vector<vector<int> >&ans)
    {
        vis[s] = 1;
        
        path.push_back(s);
        
        if(s==t)
        {
            ans.push_back(path);
        }
        else
        {
            for(auto it:graph[s])
            {
                if(!vis[it])
                {
                    fun(it,t,graph,vis,path,ans);
                }
            }
        }
        path.pop_back();
        vis[s]=0;
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) 
    {
        int n = graph.size();
        int s = 0;
        int t = n-1;
        
        vector<int>vis(n,0);
        vector<vector<int>>ans;
        vector<int>path;
        
        fun(s,t,graph,vis,path,ans);
        
        return ans;
        
    }
};