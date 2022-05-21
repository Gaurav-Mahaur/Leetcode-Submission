class Solution {
public:
    vector<int> sortArray(vector<int>& nums)
    {
         priority_queue <int, vector<int>, greater<int>> minh;
        
        for (int i=0;i<nums.size();i++)
        {
            minh.push(nums[i]);   
        }
        
        vector <int> v;
        while(minh.size()>0)
        {
            v.push_back(minh.top());
            minh.pop();
        }
        return v;
        
    }
};