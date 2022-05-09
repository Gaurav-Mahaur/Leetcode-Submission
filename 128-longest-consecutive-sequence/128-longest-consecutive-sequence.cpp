class Solution {
public:
    int longestConsecutive(vector<int>& nums)
    {
        int n = nums.size();
        
       unordered_set<int>st;
        for(int i=0;i<n;i++)
        {
            st.insert(nums[i]);
        }
        int ans = 0;
        for(int i=0;i<n;i++)
        {
            if(st.count(nums[i]-1))
            {
                continue;
            }
            int j=1;
            while(st.count(nums[i]+j))
            {
                j++;
            }
            ans = max(ans,j);
        }
        return ans;
    }
};