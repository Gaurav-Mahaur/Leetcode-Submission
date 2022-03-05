class Solution {
public:
    string destCity(vector<vector<string>>& paths) 
    {
        int n = paths.size();
        
        map<string,int>mp;
        for(int i=0;i<n;i++)
        {
            mp[paths[i][0]]++;
        }
        for(int i=0;i<n;i++)
        {
            if(mp[paths[i][1]]<=0)
            {
                return paths[i][1];
            }
        }
        return "";
        
    }
};