class Solution {
public:
    int minMoves(vector<int>& nums) 
    {
        int n = nums.size();
        int minn = *min_element(nums.begin(),nums.end());
        
        int sum=0;
        for(int i=0;i<n;i++)
        {
            sum += (nums[i]-minn);
        }
        return sum;
    }
};