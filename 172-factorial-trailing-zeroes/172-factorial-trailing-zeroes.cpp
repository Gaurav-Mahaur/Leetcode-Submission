class Solution {
public:
    int trailingZeroes(int n)
    {
        int sum =0;
        int k = 5;
        while(n/k>0)
        {
            sum += n/k;
            k = k*5;
        }
        return sum;
        
    }
};