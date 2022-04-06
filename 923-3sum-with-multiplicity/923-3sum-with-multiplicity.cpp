class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) 
    {
        int n = arr.size();
        int cnt=0;
        unordered_map<int,int>mp;
        int mod = 1e9 + 7;
        for(int i=0;i<n;i++)
        {
            cnt = (cnt + mp[target-arr[i]])%mod;
            
            for(int j=0;j<i;j++)
            {
                mp[arr[i]+arr[j]]++;
            }
            
        }
        return cnt%mod;
        
    }
};