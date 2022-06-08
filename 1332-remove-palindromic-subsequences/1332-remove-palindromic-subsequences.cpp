class Solution {
public:
    bool ispallindrome(string s,int i,int j)
    {
        if(i>=j)
        {
            return true;
        }
        while(i<j)
        {
            if(s[i]!=s[j])
            {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    int removePalindromeSub(string s) 
    {
        int n= s.size();
        if(n==0)
        {
            return 0;
        }
        if(ispallindrome(s,0,n-1))
        {
            return 1;
        }
        return 2;
        
        
    }
};