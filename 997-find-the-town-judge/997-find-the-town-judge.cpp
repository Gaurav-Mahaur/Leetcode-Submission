class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust)
    {
        int n1 = trust.size();
        vector<int>adj[n+1];
        for(int i=0;i<n1;i++)
        {
            int x= trust[i][0];
            int y = trust[i][1];
            adj[x].push_back(y);
        }
        vector<int>indegree(n+1,0);
       // indegree[0]=0;
        vector<int>outdegree(n+1,0);
        for(int i=1;i<=n;i++)
        {
            for(auto it:adj[i])
            {
                indegree[it]++;
            }
        }
        int maxx = *max_element(indegree.begin(),indegree.end());
        for(int i=1;i<=n;i++)
        {
            for(auto it:adj[i])
            {
                outdegree[i]++;
            }
        }
        for(int i=1;i<=n;i++)
        {
            if(outdegree[i]==0 && indegree[i]==n-1)
            {
             //   cout<<outdegree[i]<<endl;
                return i;
            }
        }
       
        return -1;
        
    }
};