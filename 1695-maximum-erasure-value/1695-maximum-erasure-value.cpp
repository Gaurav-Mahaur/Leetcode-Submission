class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) 
    {
        int n = nums.size();
        
        set<int>st;
        int j=0;
        int i=0;
        int currsum=0;
        int ans = INT_MIN;
        while(i<n)
        {
            while(st.find(nums[i])!=st.end() && j<i)
            {
                currsum -= nums[j];
                st.erase(nums[j]);
                j++;
            }
            currsum += nums[i];
            ans = max(ans,currsum);
            
            st.insert(nums[i]);
            i++;
        }
        return ans;
        
    }
};