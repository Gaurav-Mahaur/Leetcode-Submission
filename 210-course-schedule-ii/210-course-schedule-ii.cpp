class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) 
    {
        int n = numCourses;
        int m = prerequisites.size();
        vector<int>adj[n];
        for(int i=0;i<m;i++)
        {
            int x = prerequisites[i][0];
            int y = prerequisites[i][1];
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
        queue<int>q;
        for(int i=0;i<n;i++)
        {
            if(indegree[i]==0)
            {
                q.push(i);
            }
        }
        vector<int>v;
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            
            v.push_back(node);
            
            for(auto it:adj[node])
            {
                indegree[it]--;
                if(indegree[it]==0)
                {
                    q.push(it);
                }
            }
        }
        reverse(v.begin(),v.end());
        if(v.size()==n)
        {
            return v;
        }
        return {};
        
    }
};