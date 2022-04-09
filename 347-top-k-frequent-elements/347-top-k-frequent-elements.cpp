class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k)
    {
        int n= nums.size();
        map<int,int> mp;
        for(int i=0;i<n;i++)
        {
            mp[nums[i]]++;    
        }
        priority_queue<pair<int,int> > pq;
        for(auto it : mp)
        {
            pq.push({it.second,it.first});
        }
        vector<int> v;
        while(k--)
        {
            int a = pq.top().second;
            pq.pop();
            v.push_back(a);
        }
        return v;
        
    }
};