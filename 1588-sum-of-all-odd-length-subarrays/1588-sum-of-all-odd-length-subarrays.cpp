class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) 
    {
        int n = arr.size();
        int sum=0;
        for(int i=0;i<n;i++)
        {
            for(int j=i;j<n;j++)
            {
                for(int k=i;k<=j;k++)
                {
                    if((j-i+1)%2==1)
                    {
                        sum += arr[k];
                    }
                }
            }
        }
        return sum;
        
    }
};