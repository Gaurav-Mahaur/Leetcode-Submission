class Solution {
public:
    string longestPalindrome(string s)
    {
        int l,h;
        int start=0;
        int end=1;

        for(int i=1;i<s.size();i++)
        {
            l= i-1;
            h = i;

            while(l>=0 && h<s.length()&& s[l]==s[h])
            {
                l--;
                h++;
            }
            ++l;
            --h;
            if(s[l]==s[h] && h-l+1>end)
            {
                start = l;
                end = h-l+1;
            }
            
        
            l = i-1;
            h = i+1;
        
             while(l>=0 && h<s.length()&& s[l]==s[h])
            {
                l--;
                h++;
            }
            ++l;h--;
            if(s[l]==s[h] && h-l+1>end)
            {
                start=l;
                end = h-l+1;
            }
        }
        string s1="";
        while(end--)
        {
            s1 += s[start++];
        }
        
        return s1;
        
    }
};