class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) 
    {
        int n= dist.size();
        
        if(n==1)
        {
            return 1;
        }
       //
        vector<int>temp(n);
        for(int i=0;i<n;i++)
        {
            temp[i] = ceil((1.0*dist[i])/(speed[i]));
        }
        sort(temp.begin(),temp.end());
        int cnt=1;
        for(int i=0;i<n;i++)
        {
            if(cnt>temp[i])
            {
               return i;
            }
            cnt++;
            
        }
        return  n;
        
        
    }
};