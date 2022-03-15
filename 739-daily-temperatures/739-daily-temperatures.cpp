class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) 
    {
        int n = temperatures.size();
        stack<int>st;
        vector<int>ans;
        for(int i=n-1;i>=0;i--)
        {
            if(st.empty())
            {
                ans.push_back(-1);
            }
            else if(temperatures[st.top()]>temperatures[i])
            {
                ans.push_back(st.top());
            }
            else
            {
                while(st.size() && temperatures[i]>=temperatures[st.top()])
                {
                    st.pop();
                }
                if(st.size()==0)
                {
                    ans.push_back(i);
                }
                else
                {
                    ans.push_back(st.top());
                }
            }
            st.push(i);
        }
        reverse(ans.begin(),ans.end());
        vector<int>res(n);
        for(int i=0;i<n;i++)
        {
            if(ans[i]==-1)
            {
                res[i]=0;
            }
            else
            {
                res[i] = abs(i-ans[i]);
            }
        }
        return res;
        
        
    }
};