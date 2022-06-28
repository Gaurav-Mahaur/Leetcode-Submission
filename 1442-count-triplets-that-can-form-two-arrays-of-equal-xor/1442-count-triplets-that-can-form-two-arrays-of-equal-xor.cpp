class Solution {
public:
    int countTriplets(vector<int>& arr) 
    {
        int n = arr.size();
        if(n==1)
        {
            return 0;
        }
        int currxor=0;
        map<int,vector<int>>mp;
        int ans=0;
        for(int i=0;i<n;i++)
        {
            currxor = currxor^arr[i];
            if(currxor==0)
            {
                ans += i;
            }
            if(mp.find(currxor)!=mp.end())
            {
                for(int j=0;j<mp[currxor].size();j++)
                {
                    ans += i-(mp[currxor][j]+1);
                }
            }
                mp[currxor].push_back(i);
            
        }
        return ans;
        
    }
};