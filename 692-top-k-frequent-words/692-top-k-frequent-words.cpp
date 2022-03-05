class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k)
    {
        map<string,int>mp;
        int n = words.size();
        for(int i=0;i<n;i++)
        {
            mp[words[i]]++;
        }
        priority_queue<pair<int,string> > pq;
        for(auto it :mp)
        {
            pq.push({-it.second,it.first});
            if(pq.size()>k)
            {
                pq.pop();
            }
        }
        vector<string> v;
        while(k--)
        {
            pair<int,string> t = pq.top();
            pq.pop();
            v.push_back(t.second);
        }
        reverse(v.begin(),v.end());
        return v;
        
    }
};