class Solution {
public:
    long long int helping(long long int n)
    {
        long long int cnt=0;
        if(n==1)
        {
            return cnt;
        }
        if(n%2==0)
        {
            cnt = helping(n/2)+1;
        }
        else
        {
            cnt = min(helping(n-1),helping(n+1))+1;
        }
        
        return cnt;
    }
    int integerReplacement(int n) 
    {
        return helping((long long int)n);
          
    }
};