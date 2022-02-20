class Solution {
public:
    vector<long long> maximumEvenSplit(long long finalSum) 
    {
        
        long long int n = finalSum;
        if(n%2==1)
        {
            return {};
        }
        long long int i=1;
        long long int sum=0;
        vector<long long int>ans;
        while(sum<n)
        {
            sum += 2*i;
            if(sum>n)
            {
                break;
            }
            ans.push_back(2*i);
            i++;
        }
        cout<<2*i<<endl;
        if(sum>n)
        {
            sum -= 2*i;
        }
        long long int diff = n-sum;
        int k = ans.size();
       ans[k-1] = ans[k-1]+diff;
        cout<<ans[k-1]<<endl;
        return ans;
       
        
        
    }
};