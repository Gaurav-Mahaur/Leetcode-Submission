class Solution {
public:
    void nextsmallertoleft(vector<int>&a,int n,vector<int>&t)
    {
        stack<pair<int,int> >st;
        for(int i=0;i<n;i++)
        {
            if(st.empty())
            {
                t.push_back(0);
            }
            else if(!st.empty() && st.top().first<a[i])
            {   
                t.push_back(st.top().second+1);
            }
            else
            {
                while(!st.empty() && st.top().first>=a[i])
                {
                     st.pop();
                }
                if(st.empty())
                {
                    t.push_back(0);
                }
                else
                {
                    t.push_back(st.top().second+1);
                }
            }
            st.push({a[i],i});
        }
    //reverse(t.begin(),t.end());
    }
    void nextsmallertoright(vector<int>&a,int n,vector<int>&t)
    {
//
        stack<pair<int,int> >st;
        for(int i=n-1;i>=0;i--)
        {
            if(st.empty())
            {
                t.push_back(n-1);
            }
            else if(!st.empty() && st.top().first<a[i])
            {
                t.push_back(st.top().second-1);
            }
            else
            {
                while(!st.empty() && st.top().first>=a[i])
                {
                    st.pop();
                }
                if(st.empty())
                {   
                    t.push_back(n-1);
                }
                else
                {
                    t.push_back(st.top().second-1);
                }
            }
            st.push({a[i],i});
        }
        reverse(t.begin(),t.end());
    }
    int fun(vector<int>&a,int n)
    {
        vector<int>t1,t2;

        nextsmallertoleft(a,n,t1);
        nextsmallertoright(a,n,t2);
        int ans = 0;

        for(int i=0;i<n;i++)
        {
            ans = max(ans,(t2[i]-t1[i]+1)*a[i]);
        }

        return ans;

    }
    int maximalRectangle(vector<vector<char>>& matrix) 
    {
        int n = matrix.size();
        int m = matrix[0].size();
        
        int ans=0;
        vector<int>v(m,0);
        for(int i=0;i<n;i++)
        {

            for(int j=0;j<m;j++)
            {
                if(matrix[i][j]=='0')
                {
                    v[j]=0;
                }
                else
                {
                    v[j] += matrix[i][j]-'0';
                }
            }
            //cout<<fun(v,m)<<endl;
            ans = max(ans,fun(v,m));
        }
        return ans;
        
    }
};