class Solution {
public:
    int findLucky(vector<int>& arr) 
    {
        int n = arr.size();
        map<int,int>mp;
        for(int i=0;i<n;i++)
        {
            mp[arr[i]]++;
        }
        int k=-1;
        for(auto it:mp)
        {
            if(it.first==it.second)
            {
                k = it.first;
            }
        }
        return k;
        
    }
};