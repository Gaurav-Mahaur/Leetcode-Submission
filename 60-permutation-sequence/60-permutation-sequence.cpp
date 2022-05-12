class Solution {
public:
    // void permute(string s,int l,int r,vector<string>&ans)
    // {
    //     if(l==r)
    //     {
    //         ans.push_back(s);
    //         return;
    //     }
    //     for(int i=l;i<=r;i++)
    //     {
    //         swap(s[i],s[l]);
    //         permute(s,l+1,r,ans);
    //         swap(s[i],s[l]);
    //     }
    // }
        
    string getPermutation(int n, int k) 
    {
        vector<int>nums;
        int fact =1;
        for(int i=1;i<n;i++)
        {
            fact = fact*i;
            nums.push_back(i);
        }
        nums.push_back(n);
        k = k-1;
        string ans="";
        
        while(1)
        {
            ans += to_string(nums[k/fact]);
            nums.erase(nums.begin()+k/fact);
            if(nums.size()==0)
            {
                break;
            }
            k = k%fact;
            fact = fact/nums.size();
            
        }
        return ans;
    }
};