class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) 
    {
        int n = pushed.size();
        stack<int>st;
         int j=0;
        for(int i=0;i<n;i++)
        {
            st.push(pushed[i]);
            
            if(st.top() == popped[j])
            {
                while(!st.empty() && st.top() == popped[j] && j<n)
                {
                    st.pop();
                    j++;
                }
            }
        }
        if(st.size())
        {
            return false;
        }
        return true;
        
    }
};