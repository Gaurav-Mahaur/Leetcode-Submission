class Solution {
public:
    int count(int n)
    {
        int k = n;
        int cnt=0;
        if(k==0)
            return 0;
        
        while(k>0)
        {
            if(k&1)
            {
                cnt++;
            }
            k = k>>1;
        }
        return cnt;
    }
    vector<int> countBits(int n)
    {
        vector<int>v;
        for(int i=0;i<=n;i++)
        {
            int k = count(i);
            v.push_back(k);
        }
        return v;
        
    }
};