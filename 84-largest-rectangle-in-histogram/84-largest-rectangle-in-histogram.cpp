class Solution {
public:
    int largestRectangleArea(vector<int>& heights) 
    {
        int n = heights.size();
        vector<int>t1,t2;
        stack<pair<int,int> >st;
        for(int i=n-1;i>=0;i--)
        {
            if(st.empty())
            {
                t1.push_back(n-1);
            }
            else if(!st.empty() && st.top().first<heights[i])
            {
                t1.push_back(st.top().second -1);
            }
            else
            {
                while(!st.empty() && st.top().first>=heights[i])
                {
                    st.pop();
                }
                if(st.empty())
                {
                    t1.push_back(n-1);
                }
                else
                {
                    t1.push_back(st.top().second-1);
                }
            }
            st.push({heights[i],i});
                
        }
        reverse(t1.begin(),t1.end());
        
        while(!st.empty())
        {
            st.pop();
        }
       for(int i=0;i<n;i++)
        {
            if(st.empty())
            {
                t2.push_back(0);
            }
            else if(!st.empty() && st.top().first<heights[i])
            {
                t2.push_back(st.top().second +1);
            }
            else
            {
                while(!st.empty() && st.top().first>=heights[i])
                {
                    st.pop();
                }
                if(st.empty())
                {
                    t2.push_back(0);
                }
                else
                {
                    t2.push_back(st.top().second+1);
                }
            }
            st.push({heights[i],i});
                
        }
        int ans = 0;
        int area = 0;
        for(int i=0;i<n;i++)
        {
            area = abs(t1[i]-t2[i]+1)*heights[i];
            ans = max(ans,area);
        }
        
        return ans;
        
    }
};