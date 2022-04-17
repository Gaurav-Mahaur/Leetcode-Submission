class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) 
    {
        int n =barcodes.size();
        if(n==1)
        {
            return barcodes;
        }
        map<int,int>mp;
        priority_queue<pair<int,int>>pq;
        for(int i=0;i<n;i++)
        {
            mp[barcodes[i]]++;
        }
        for(auto it:mp)
        {
            pq.push({it.second,it.first});
        }
        vector<int>ans;
        while(pq.size()>1)
        {
            int c1 = pq.top().first;
            int a1 = pq.top().second;
            pq.pop();
            int c2 = pq.top().first;
            int a2 = pq.top().second;
            pq.pop();
            ans.push_back(a1);
            ans.push_back(a2);
            c1 = c1-1;
            c2 = c2-1;
            
            if(c1>0)
            {
                pq.push({c1,a1});
            }
            if(c2>0)
            {
                pq.push({c2,a2});
            }
        }
        if(pq.size()>0)
        {
            int k = pq.top().second;
            ans.push_back(k);
            pq.pop();
        }
        return ans;
        
    }
};