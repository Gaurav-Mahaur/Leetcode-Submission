// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
	int isNegativeWeightCycle(int n, vector<vector<int>>edges){
	    // Code here\
	    
	    vector<int>dist(n,INT_MAX);
	    dist[0]=0;
	    for(int i=0;i<n-1;i++)
	    {
	        for(int j=0;j<edges.size();j++)
	        {
	            int u = edges[j][0];
	            int v = edges[j][1];
	            int wt = edges[j][2];
	            if(dist[u]!=INT_MAX && dist[v]>dist[u]+wt)
	            {
	                dist[v] = dist[u]+wt;
	            }
	        }
	    }
	    for(int i=0;i<edges.size();i++)
	    {
	        int u = edges[i][0];
	        int v = edges[i][1];
	        int wt=edges[i][2];
	        if(dist[v]>dist[u]+wt)
	        {
	            return true;
	        }
	    }
	    return false;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>edges;
		for(int i = 0; i < m; i++){
			int x, y, z;
			cin >> x >> y >> z;
			edges.push_back({x,y,z});
		}
		Solution obj;
		int ans = obj.isNegativeWeightCycle(n, edges);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends