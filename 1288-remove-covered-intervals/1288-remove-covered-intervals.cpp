class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) 
    {
        int n = intervals.size();
        
        sort(intervals.begin(),intervals.end());
        int cnt=0;
        int left=-1;
        int right=-1;
        for(int i=0;i<n;i++)
        {
           if(intervals[i][0]>left && intervals[i][1]>right)
           {
               cnt++;
               left = intervals[i][0];
           }
            right = max(right,intervals[i][1]);
        }
        return cnt;
    }
};