class Solution {
public:
    int heightChecker(vector<int>& heights) 
    {
        int n = heights.size();
        vector<int>temp = heights;
        sort(temp.begin(),temp.end());
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            if(temp[i]!=heights[i])
            {
                cnt++;
            }
        }
        return cnt;
        
    }
};