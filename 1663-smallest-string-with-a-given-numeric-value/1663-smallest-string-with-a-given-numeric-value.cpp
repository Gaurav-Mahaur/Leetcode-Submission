class Solution {
public:
    string getSmallestString(int n, int k) 
    {
        string s ="";
        for(int i=0;i<n;i++)
        {
            s += 'a';
        }
        k = k-n;
        int i=n-1;
        
        while(k>0)
        {
            if(k>=25)
            {
                s[i] = 'z';
                k -= 25;
            }
            else
            {
                s[i] += k;
                k -=k;
            }
            i--;
        }
        
        return s;
        
    }
};