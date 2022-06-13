class Solution {
public:
    int minFlips(string target) 
    {
        int n = target.size();
        string s ="";
        for(int i=0;i<n;i++)
        {
            s += "0";
        }
        int cnt=0;
        char check = '0';
        for(int i=0;i<n;i++)
        {
            if(target[i]!=check)
            {
                cnt++;
                check = target[i];
            }
           
            
        }
        return cnt;
        
    }
};