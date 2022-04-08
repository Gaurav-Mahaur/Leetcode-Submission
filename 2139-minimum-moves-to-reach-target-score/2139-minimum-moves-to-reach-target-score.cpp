class Solution {
public:
    int minMoves(int target, int maxDoubles) 
    {
        int cnt=0;
        int m = maxDoubles;
        
        while(target!=1)
        {
            if(target%2==0 && m>0)
            {
                target = target/2;
                cnt++;
                m--;
            }
            else if(target%2==1 && m>0)
            {
                target = target-1;
                cnt++;
            }
            else if(m==0)
            {
                cnt += target-1;
                target =1;
            }
            
        }
        return cnt;
        
    }
};