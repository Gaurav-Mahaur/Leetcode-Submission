class Solution {
public:
    int numSub(string s) 
    {
        int n = s.size();
        long long int l=0;
        
        long int sum=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='0')
            {
                sum += ((l+1)*l)/2;
                sum = sum%1000000007;
                l=0;
            }
            else if(s[i]=='1')
            {
                l++;
                
            }
        }
        if(l!=0)
        {
            sum += ((l+1)*l)/2;
            sum = sum%1000000007;
        }
        return sum%1000000007;
        
    }
};