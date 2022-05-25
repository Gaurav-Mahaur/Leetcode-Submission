class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) 
    {
        int n = nums1.size();
        int m = nums2.size();
        vector<int>ans;
        stack<int>st;
        vector<int>t;
        map<int,int>mp;
        for(int i=0;i<m;i++)
        {
            mp[nums2[i]]=i;
        }
        for(int i=m-1;i>=0;i--)
        {
            if(st.empty())
            {
                t.push_back(-1);
            }
            else if(!st.empty() && st.top()>nums2[i])
            {
                t.push_back(st.top());
            }
            else
            {
                while(!st.empty() && st.top()<=nums2[i])
                {
                    st.pop();
                }
                if(!st.empty())
                {
                    t.push_back(st.top());
                }
                else
                {
                    t.push_back(-1);
                }
            }
            st.push(nums2[i]);
        }
        reverse(t.begin(),t.end());
        for(int i=0;i<m;i++)
        {
            cout<<t[i]<<" "; 
        }
        for(int i=0;i<n;i++)
        {
            int idx = mp[nums1[i]];
            ans.push_back(t[idx]);
        }
        return ans;
        
    }
};