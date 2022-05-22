class Solution {
public:
    string reorganizeString(string s) 
    {
        int n = s.size();
        map<char,int>mp;
        for(int i=0;i<n;i++)
        {
            mp[s[i]]++;
        }
        priority_queue<pair<int,char>>pq;
        
        for(auto it:mp)
        {
            pq.push({it.second,it.first});
        }
        string ans = "";
        
        while(pq.size()>1)
        {
            pair<int,char>a = pq.top();
            pq.pop();
            pair<int,char>b = pq.top();
            pq.pop();
            
            ans += a.second;
            ans += b.second;
            
            a.first--;
            b.first--;
            if(a.first>0)
            {
                pq.push(a);
            }
            if(b.first>0)
            {
                pq.push(b);
            }
        }
        if(pq.size()>0)
        {
            if(pq.top().first>1)
            {
                return "";
            }
            else
            {
                ans += pq.top().second;
                pq.pop();
            }
        }
        return ans;
        
    }
};