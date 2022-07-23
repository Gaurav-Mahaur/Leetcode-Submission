class Solution {
public:
    void merge(vector<pair<int,int>>&t,int l,int m,int r,vector<int>&cnt)
    {
        vector<pair<int,int>>temp(r-l+1,{0,0});
        
        int i=l;
        int j=m+1;
        
        int k=0;
        
        while(i<=m && j<=r)
        {
            if(t[i].first<=t[j].first)
            {
                temp[k++] = t[j++];
            }
            else
            {
               cnt[t[i].second] += r-j+1;
                temp[k++] = t[i++];
            }
        }
        while(i<=m)
        {
            temp[k++] = t[i++];
        }
        while(j<=r)
        {
            temp[k++] = t[j++];
        }
        for(int i=l;i<=r;i++)
        {
            t[i] = temp[i-l];
        }
    }
    void mergesort(vector<pair<int,int>>&t,int l,int r,vector<int>&cnt)
    {
        if(l>=r)return;
        else
        {
            int m = l+(r-l)/2;
            
            mergesort(t,l,m,cnt);
            mergesort(t,m+1,r,cnt);
            
            merge(t,l,m,r,cnt);
        }
    }
    vector<int> countSmaller(vector<int>& nums) 
    {
        int n = nums.size();
        vector<int>fq(n,0);
        vector<pair<int,int>>t;
        for(int i=0;i<n;i++)
        {
            t.push_back({nums[i],i});
        }
        mergesort(t,0,n-1,fq);
        
        return fq;
        
    }
};