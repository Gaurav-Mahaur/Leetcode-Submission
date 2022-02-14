class Solution {
public:
    
    int networkDelayTime(vector<vector<int>>& times, int n, int k) 
    {
        int m = times.size();
        vector<pair<int,int> >adj[n+1];
        for(int i=0;i<m;i++)
        {
            int x= times[i][0];
            int y = times[i][1];
            int w = times[i][2];
            adj[x].push_back({y,w});
        }
        vector<int>dist(n+1,INT_MAX);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,k});
        //vis[k]=1;
        dist[k]=0;
        while(!pq.empty())
        {
            pair<int,int> t = pq.top();
            pq.pop();
            int u = t.second;
            
            for(auto it:adj[u])
            {
                int v = it.first;
                int wt = it.second;
                if(dist[v]>dist[u]+wt)
                {
                    dist[v]=dist[u]+wt;
                    pq.push({dist[v],v});
                }
            }
        }
        int ans = INT_MIN;
        for(int i=1;i<=n;i++)
        {
            ans = max(ans,dist[i]);
        }
        
        if(ans==INT_MAX)
        {
            return -1;
        }
        return ans;
    }
    
};