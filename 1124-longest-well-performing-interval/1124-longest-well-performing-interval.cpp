class Solution {
public:
    int longestWPI(vector<int>& hours) 
    {
        int n = hours.size();
        for(int i=0;i<n;i++)
        {
            if(hours[i]>8)
            {
                hours[i]=1;
            }
            else
            {
                hours[i]=-1;
            }
        }
        
        map<int,int>mp;
        int currsum=0;
        int maxx = 0;
        int len=0;
        for(int i=0;i<n;i++)
        {
            currsum += hours[i];
            
            if(currsum>0)
            {
                maxx = max(maxx,i+1);
            }
            else if(mp.find(currsum)==mp.end())
            {
                mp[currsum]=i;
            }
                if(mp.find(currsum-1)!=mp.end())
                {
                    maxx = max(maxx,i-mp[currsum-1]);
                }
            
            
            
        }
        return maxx;
    }
};