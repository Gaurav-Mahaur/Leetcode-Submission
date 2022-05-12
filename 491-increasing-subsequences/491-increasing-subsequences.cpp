class Solution {
public:
    void fun(int idx,vector<int>nums,int n,vector<int>&temp,set<vector<int> > &ans)
    {
        if(idx>=n)
        {
            ans.insert(temp);
            return;
        }
        temp.push_back(nums[idx]);
        fun(idx+1,nums,n,temp,ans);
        temp.pop_back();
        
        fun(idx+1,nums,n,temp,ans);
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) 
    {
        set<vector<int> >ans;
        vector<int>temp;
        int n = nums.size();
        
        fun(0,nums,n,temp,ans);
        vector<vector<int> >fin;
        for(auto it:ans)
        {
            vector<int>t = it;
            int flag=0;
            if(t.size()<2)
            {
                continue;
            }
            for(int j=1;j<t.size();j++)
            {
                if(t[j]<t[j-1])
                {
                    flag=1;
                }
            }
            if(flag==0 && t.size()>=2)
            {
                fin.push_back(t);
            }
        }
        return fin;
    }
};