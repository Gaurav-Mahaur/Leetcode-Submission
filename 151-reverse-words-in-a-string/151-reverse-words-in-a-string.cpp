class Solution {
public:
    string reverseWords(string s) 
    {
        int n = s.size();
        
        stack<string>st;
        for(int i=0;i<n;i++)
        {
            string word = "";
            if(s[i]!=' ')
            {
                while(s[i]!=' ' &&  i<n)
                {
                    word += s[i];
                    i++;
                }
                st.push(word);
            }
        }
        string ans = "";
        cout<<st.size()<<endl;
        while(st.size()>1)
        {
            ans += st.top()+' ';
            st.pop();
        }
        ans += st.top();
        
        return ans;
            
    }
};