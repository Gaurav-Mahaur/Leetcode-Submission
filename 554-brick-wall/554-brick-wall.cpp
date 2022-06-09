class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        int n = wall.size();
        int sum=0;
        for(int i=0;i<n;i++)
        {
            vector<int>t = wall[i];
            if(wall[i].size()==1)
            {
                continue;
            }
            for(int j=1;j<t.size();j++)
            {
                t[j] = t[j-1]+t[j];
            }
            wall[i] = t;
        }
        sum = wall[0][wall[0].size()-1];
        unordered_map<int,int>mp;
        unordered_map<int,int> :: iterator it;
      for(int i=0;i<n;i++)
        {
            for(int j=0;j<wall[i].size();j++)
            {
               mp[wall[i][j]]++;
            }
        }
        mp[sum]=0;
        int mx=0;
        for(auto a: mp){
         mx=max(a.second,mx);
        }
        //cout<<mx<<endl;
        return n-mx;
        
    }
};