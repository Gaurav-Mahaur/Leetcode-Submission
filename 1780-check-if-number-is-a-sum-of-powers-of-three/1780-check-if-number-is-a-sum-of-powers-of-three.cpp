class Solution {
public:
    bool checkPowersOfThree(int n) 
    {
       while(n)
       {
           if(n%3==0)
           {
               n =n/3;
           }
           else if(n%3==1)
           {
               n -= 1;
           }
           else
           {
               return false;
           }
       }
        return true;
        
    }
};