class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) 
    {
        int n = nums.size();
       // vector<int>v;
    set<long long int>st;
    for(int i=0;i<n;i++)
    {
        string s = nums[i];
        long long int number = 0;
        for(int j=0;j<n;j++)
        {
            number += (s[j]-48)*(ceil(pow(2,n-j-1)));
        }
        st.insert(number);
    }
    long long int k=0;
    for(int i=0;i<(1<<n);i++)
    {
        if(st.find(i)==st.end())
        {
            k = i;
            break;
        }
    }
    string ans="";
    int f=n;
    while(f--)
    {
        if(k&1)
        {
            ans += '1';
        }
        else
        {
            ans += '0';
        }
        k = k>>1;
    }
   // cout<<ans<<endl;
        reverse(ans.begin(),ans.end());
      return ans;  
    }
};