class Solution {
public:
    static bool cmp(pair<int,int>p1,pair<int,int>p2)
    {
        if(p1.second==p2.second)
        {
            return p1.first>p2.first;
        }
        return p1.second>p2.second;
    }
    vector<int> getStrongest(vector<int>& arr, int k) 
    {
        int n = arr.size();
        vector<int>t = arr;
        sort(t.begin(),t.end());
        int m = t[(n-1)/2];
        vector<pair<int,int>>v;
        for(int i=0;i<n;i++)
        {
            v.push_back({arr[i],abs(arr[i]-m)});
        }
        sort(v.begin(),v.end(),cmp);
        vector<int>ans;
        for(int i=0;i<k;i++)
        {
           ans.push_back(v[i].first);
        }
        return ans;
        
    }
};