// { Driver Code Starts
//Initial Template for C

#include <stdio.h>
#include <stdlib.h>


 // } Driver Code Ends
//User function Template for C


// arr[]: Input Array
// N : Size of the Array arr[]
// Function to count inversions in the array.
long long int inversion(long long int a[],long long int l,long long int m,long long int r)
{
    long long int n1 = m-l+1;
    long long int n2 = r-m;
    long long int a1[n1],a2[n2];
    for(int i=0;i<n1;i++)
    {
        a1[i] = a[l+i];
    }
    for(int i=0;i<n2;i++)
    {
        a2[i] = a[m+1+i];
    }
    long long int i=0;
    long long int j=0;
    long long int inv=0;
    long long int k=l;
    while(i<n1 && j<n2)
    {
        if(a1[i]<=a2[j])
        {
            a[l]=a1[i];
            i++;l++;
        }
        else
        {
            a[l]=a2[j];
            inv += n1-i;
            j++;l++;
        }
    }
    while(i<n1)
    {
        a[l]=a1[i];
        i++;l++;
    }
    while(j<n2)
    {
        a[l]=a2[j];
        j++;l++;
    }
    
    
    
    return inv;
}
long long int countinversion(long long int a[],long long int l,long long int r)
{
    long long int inv=0;
    if(l<r)
    {
        long long int m = (l+r)/2;
        inv += countinversion(a,l,m);
        inv += countinversion(a,m+1,r);
        inv += inversion(a,l,m,r);
    }
    return inv;
}
long long int inversionCount(long long arr[], long long N)
{
    // Your Code Here
    return countinversion(arr,0,N-1);
    
}



// { Driver Code Starts.

int main() {
    
    long long T;
    scanf("%ld", &T);
    
    while(T--){
        long long N;
        scanf("%ld", &N);
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            scanf("%ld", &A[i]);
        }
        
        printf("%ld\n", inversionCount(A,N) );
    }
    
    return 0;
}
  // } Driver Code Ends