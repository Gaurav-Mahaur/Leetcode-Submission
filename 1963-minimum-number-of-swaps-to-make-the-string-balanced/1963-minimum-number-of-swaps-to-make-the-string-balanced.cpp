class Solution {
public:
    int minSwaps(string s) 
    {
        int n = s.size();
        int r=n-1;
        int cnt=0;
        int balance=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='[')
            {
                balance++;
            }
            else
            {
                balance--;
            }
            
            if(balance<0)
            {
                while(s[r]==']')
                {
                    r--;
                }
                swap(s[i],s[r]);
                cnt++;
                balance=1;
            }
        }
        return cnt;
        
    }
};