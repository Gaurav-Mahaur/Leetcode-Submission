class Solution {
public:
int mergefun(vector<int>&a,int l,int m,int r)
{
    int n1 = m-l+1;
    int n2 =r-m;
    int a1[n1];
    int a2[n2];
    for(int i=0;i<n1;i++)
    {
        a1[i] = a[l+i];
    }
    for(int i=0;i<n2;i++)
    {
        a2[i] = a[m+1+i];
    }
    int cnt=0;
    int i=0;
    int j=0;
    while(i<n1 && j<n2)
    {
        if(a1[i] > 2LL * a2[j])
        {
            cnt += n1-i;
            j++;
        }
        else
        {
            i++;
        }
    }
     i=0;
     j=0;
    int k=l;
    while(i<n1 && j<n2)
    {
        if(a1[i]<a2[j])
        {
            a[k]=a1[i];
            i++;
            k++;
        }
        else
        {
            a[k]=a2[j];
            j++;
            k++;
        }
    }
    while(i<n1)
    {
        a[k]=a1[i];
        i++;
        k++;
    }
    while(j<n2)
    {
        a[k]=a2[j];
        j++;
        k++;
    }

    return cnt;
}
int mergesort(vector<int>&a,int l,int r)
{
    int cnt=0;
    if(l<r)
    {
        int m = (l+r)/2;
        cnt += mergesort(a,l,m);
        cnt += mergesort(a,m+1,r);
        cnt += mergefun(a,l,m,r);
    }
    return cnt;
}
    int reversePairs(vector<int>& nums) 
    {
        int n = nums.size();
        int l =0;
        int r = n-1;
        if(n==1)
        {
            return 0;
        }
        return mergesort(nums,l,r);
        
    }
};