// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution 
{
    public:
    //Function to find out minimum steps Knight needs to reach target position.
    bool isvalid(int x,int y,vector<vector<int> >&dis,int n)
    {
        if(x<1||y<1||x>n||y>n)
        {
            return false;
        }
        if(dis[x][y]!=-1)
        {
            return false;
        }
        return true;
    }
    void minnstep(int x1,int y1,vector<vector<int> > &dis,int n)
    {
        dis[x1][y1]=0;
        
        int dx[] = {-2,-2,-1,1,2,2,1,-1};
        int dy[] = {-1,1,2,2,1,-1,-2,-2};
        queue<pair<int,int> >q;
        q.push({x1,y1});
        while(!q.empty())
        {
            int currx = q.front().first;
            int curry = q.front().second;
            q.pop();
            
            for(int i=0;i<8;i++)
            {
                int newx = currx+dx[i];
                int newy = curry+dy[i];
                if(isvalid(newx,newy,dis,n))
                {
                    q.push({newx,newy});
                    dis[newx][newy] = dis[currx][curry] +1;
                }   
            }
        }
    }
	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N)
	{
	    // Code here
	    int x1,y1;
	    x1 = KnightPos[0];
        y1 = KnightPos[1];
	    int x2,y2;
	    x2 = TargetPos[0];
	    y2 = TargetPos[1];
	    
	    int n = N;
	    vector<vector<int> >dis(n+1,vector<int>(n+1,-1));
	    minnstep(x1,y1,dis,n);
	    int k =-1;
	   // for(int i=1;i<=n;i++)
	   // {
	   //     for(int j=1;j<=n;j++)
	   //     {
	   //         cout<<dis[i][j]<<" "; 
	   //     }
	   //     cout<<endl;
	   // }
	    if(dis[x2][y2]!=-1)
	    {
	         k = dis[x2][y2];
	    }
	    return k;
	    
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends