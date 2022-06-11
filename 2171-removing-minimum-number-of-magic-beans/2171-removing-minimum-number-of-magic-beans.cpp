class Solution {
public:
    long long minimumRemoval(vector<int>& beans) 
    {
        int n = beans.size();
        sort(beans.begin(),beans.end());
        vector<long long int>pref(n,0);
        vector<long long int>suff(n,0);
        if(n==1)
        {
            return 0;
        }
        for(int i=0;i<n;i++)
        {
            if(i==0)
            {
                pref[i] = beans[i];
            }
            else
            {
                pref[i] = pref[i-1]+beans[i];
            }
        }
        for(int i=n-1;i>=0;i--)
        {
            if(i==n-1)
            {
                suff[i] = beans[i];
            }
            else
            {
                suff[i] = suff[i+1]+beans[i];
            }
        }
        long long int ans = 1e13;
        long long sum = pref[n-1];
        for(int i=0;i<n;i++)
        {
    
            long long int t = sum - ((long long)(n-i)*(long long)beans[i]);
            cout<<t<<endl;
            ans = min(t,ans);
        }
        return ans;
        
    }
};