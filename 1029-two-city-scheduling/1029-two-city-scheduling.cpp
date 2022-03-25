class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) 
    {
        int n = costs.size();
        int mincost =0;
        for(int i=0;i<n;i++)
        {
            mincost += costs[i][0];
        }
        vector<int>temp;
        for(int i=0;i<n;i++)
        {
            temp.push_back(costs[i][1]-costs[i][0]);
        }
        sort(temp.begin(),temp.end());
        for(int i=0;i<n/2;i++)
        {
            mincost += temp[i];
        }
        return mincost;
    }
};