class Solution {
public:
    
    bool hasAllCodes(string s, int k) 
    {
        int n = s.size();
        unordered_set<string>st;
      
        for(int i=0;i<n-k+1;i++)
        {
            string str = s.substr(i,k);
            
            st.insert(str);
        }
      if(st.size()==(1<<k))
      {
          return true;
      }
        return false;
    }
};