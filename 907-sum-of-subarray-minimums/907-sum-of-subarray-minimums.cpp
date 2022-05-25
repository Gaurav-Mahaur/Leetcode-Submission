class Solution {
public:
    void nsr(vector<int>&arr,int n,vector<int>&a)
    {
        stack<pair<int,int>>st;
        for(int i=n-1;i>=0;i--)
        {
            if(st.empty())
            {
                a.push_back(n);
            }
            else if(!st.empty() && st.top().first<arr[i])
            {
                a.push_back(st.top().second);
            }
            else
            {
                while(!st.empty() && st.top().first>=arr[i])
                {
                    st.pop();
                }
                if(st.empty())
                {
                    a.push_back(n);
                }
                else
                {
                    a.push_back(st.top().second);
                }
            }
            st.push({arr[i],i});        
        }
        reverse(a.begin(),a.end());
    }
    void nsl(vector<int>arr,int n,vector<int>&b)
    {
        stack<pair<int,int>>st;
        for(int i=0;i<n;i++)
        {
            if(st.empty())
            {
                b.push_back(-1);
            }
            else if(!st.empty() && st.top().first<arr[i])
            {
                b.push_back(st.top().second);
            }
            else
            {
                while(!st.empty() && st.top().first>=arr[i])
                {
                    st.pop();
                }
                if(st.empty())
                {
                    b.push_back(-1);
                }
                else
                {
                    b.push_back(st.top().second);
                }
            }
            st.push({arr[i],i});        
        }
    }
    int sumSubarrayMins(vector<int>& arr) 
    {
        stack<int> s1, s2;
        int n = arr.size();
        vector<int> next_smaller(n), prev_smaller(n);
        
        
        for(int i = 0;i<n;i++){
            next_smaller[i] = n-i-1;
            prev_smaller[i] = i;
        }
        
        
        for(int i = 0;i<n;i++){
            while(!s1.empty() && arr[s1.top()]>arr[i]){
                next_smaller[s1.top()] = i - s1.top() - 1;
                s1.pop();
            }
            s1.push(i);
        }
        
        for(int i = n-1;i>=0;i--){
            while(!s2.empty() && arr[s2.top()]>=arr[i]){
                prev_smaller[s2.top()] = s2.top() - i - 1;
                s2.pop();
            }
            s2.push(i);
        }
        
        long ans = 0;
        int mod = 1e9 + 7;
        
        for(int i = 0;i<n;i++){
            ans = (ans + (long)arr[i] * (prev_smaller[i]+1) * (next_smaller[i]+1)) % mod;
            ans %= mod;
        }
        
        return ans;
        
        
        
    }
};