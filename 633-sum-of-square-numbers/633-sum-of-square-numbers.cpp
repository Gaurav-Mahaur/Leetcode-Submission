class Solution {
public:
    bool issquare(int n)
    {
        int k = sqrt(n);
        if(k*k == n)
        {
            return true;
        }
        return false;
    }
    bool judgeSquareSum(int c) 
    {
        int k = sqrt(c);
        if(c==0)
        {
            return true;
        }
        for(int i=0;i<=k;i++)
        {
            int a = c-i*i;
            if(a>0 && issquare(a))
            {
                return true;
            }
        }
        return false;
        
    }
};