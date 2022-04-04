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
        string ans="";
        while(pq.size()>1)
        {
            pair<int,char>t1 = pq.top();
            pq.pop();
            pair<int,char>t2 = pq.top();
            pq.pop();
            
            ans += t1.second;
            ans += t2.second;
            
            t1.first--;
            t2.first--;
            
            if(t1.first>0)
            {
                pq.push(t1);
            }
            if(t2.first>0)
            {
                pq.push(t2);
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
            }
        }
        return ans;
        
    }
};