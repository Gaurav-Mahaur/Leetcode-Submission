class Solution {
public:
    bool validPalindrome(string s) 
    {
        int n =s.size();
        int l =0;
        int r = n-1;
        int cnt=0;
        
        while(l<r)
        {
            if(s[l]==s[r])
            {
                l++;
                r--;
            }
            else
            {
                cnt++;
                l++;
            }
            
            if(cnt>1)
            {
                break;
            }
        }
        
        l=0;
        r=n-1;
        int cnt1=0;
        while(l<r)
        {
            if(s[l]==s[r])
            {
                l++;
                r--;
            }
            else
            {
                cnt1++;
                r--;
            }
            
            if(cnt1>1)
            {
                break;
            }
        }
        if(cnt==1 || cnt1==1)
        {
            return true;
        }
        if(cnt==0 || cnt1==0)
        {
            return true;
        }
        return false;
        
    }
};