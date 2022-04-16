class Solution {
public:
    int longestConsecutive(vector<int>& nums)
    {
        int n = nums.size();
        
        unordered_set<int>st;
        int ans=0;
        for(int i=0;i<n;i++)
        {
            st.insert(nums[i]);
        }
        
       for(auto num:nums)
       {
           if(st.count(num-1))
           {
               continue;
           }
           int j=1;
           while(st.count(num+j))
           {
               j++;
           }
           ans = max(ans,j);
       }
        return ans;
    }
};