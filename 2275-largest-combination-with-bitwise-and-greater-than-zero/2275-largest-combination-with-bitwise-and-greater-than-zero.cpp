class Solution {
public:
    int largestCombination(vector<int>& candidates) 
    {
        int n = candidates.size();
        int ans=0;
    
        for(int i=0;i<30;i++)
        {
            int cnt=0;
            for(int j=0;j<n;j++)
            {
                if(candidates[j]&(1<<i))
                {
                    cnt++;
                }
            }
            ans = max(ans,cnt);
        }
        return ans;
    }
};