class Solution {
public:
    int minAddToMakeValid(string s) 
    {
        int n = s.size();
        int balance=0;
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='(')
            {
                balance++;
            }
            else
            {
                balance--;
            }
            
            if(balance<0)
            {
                cnt++;
                balance=0;
            }
        }
        int k = cnt+balance;
        return k;
        
    }
};