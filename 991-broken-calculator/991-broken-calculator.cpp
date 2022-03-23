class Solution {
public:
    int brokenCalc(int startValue, int target) 
    {
        int n = startValue;
        int res=0;
        
        while(n<target)
        {
            if(target%2)
            {
                target = target+1;
            }
            else
            {
                target= target/2;
            }
            
            res++;
        }
        return res+n-target;
    }
};