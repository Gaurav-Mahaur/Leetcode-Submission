class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) 
    {
        vector<vector<int>>res;
        set<vector<int> >st;
        int n =nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                int target2 = target-nums[i]-nums[j];
                
                int l =j+1;
                int r = n-1;
                
                while(l<r)
                {
                    int sum = nums[l]+nums[r];
                    if(sum<target2)
                    {
                        l++;
                    }
                    else if(sum>target2)
                    {
                        r--;
                    }
                    else
                    {
                        vector<int>t(4);
                        t[0] = nums[i];
                        t[1]=nums[j];
                        t[2]=nums[l];
                        t[3]=nums[r];
                        
                        res.push_back(t);
                        
                        while(l<r && nums[l]==t[2])l++;
                        while(l<r && nums[r]==t[3])r--;
                    }
                }
                
                while(j+1<n && nums[j+1]==nums[j])j++;
            }
            
            while(i+1<n && nums[i+1]==nums[i])i++;
        }
      
        return res;
        
    }
};