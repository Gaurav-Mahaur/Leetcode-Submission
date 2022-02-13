class Solution {
public:
    char findTheDifference(string s, string t) 
    {
        int n1 = s.size();
        int n2 = t.size();
        if(n1==0)
        {
            return t[0];
        }
        char xorsum=s[0];
        for(int i=1;i<n1;i++)
        {
            xorsum =xorsum^s[i];
        }
        for(int i=0;i<t.size();i++)
        {
            xorsum =xorsum^t[i];
        }
        return xorsum;
        
    }
};