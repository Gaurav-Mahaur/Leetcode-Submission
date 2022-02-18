class Solution {
public:
    int findpar(int a,vector<int>&par)
    {
        if(par[a]==a)
        {
            return a;
        }
        return par[a] = findpar(par[a],par);
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) 
    {
        int n = edges.size();
        vector<int>par(n+1);
        vector<int>rank(n+1,0);
        for(int i=0;i<=n;i++)
        {
            par[i]=i;
        }
        
        int m = edges.size();
        vector<int>v;
        for(int i=0;i<m;i++)
        {
            int x = findpar(edges[i][0],par);
            int y=  findpar(edges[i][1],par);
            if(x!=y)
            {
                if(rank[x]<rank[y])
                {
                    par[x]=y;
                }
                else if(rank[x]>rank[y])
                {
                    par[y]=x;
                }
                else
                {
                    par[x]=y;
                    rank[y]++;
                }
            }
            else
            {
                v.push_back(edges[i][0]);
                v.push_back(edges[i][1]);
            }
        }
        
        return v;
        
    }
};