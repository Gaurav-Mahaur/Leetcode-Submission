class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        vector<int>t;
        for(int i=0;i<n;i++)
        {
            t.push_back(nums[i]);
        }
        sort(t.begin(),t.end());
        int k1=-1;
        int k2 =-1;
        for(int i=0;i<n;i++)
        {
            if(t[i]!=nums[i])
            {
                k1 = i;
                break;
            }
        }
        for(int i=n-1;i>0;i--)
        {
            if(t[i]!=nums[i])
            {
                k2 = i;
                break;
            }
        }
        if(k1>=0 && k2>=0)
        {
            return k2-k1+1;
        }
        return 0;
    }
};