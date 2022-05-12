class Solution {
public:
    static bool cmp(pair<int,int>p1,pair<int,int>p2)
    {
        return p1.second<p2.second;
    }
    int findLongestChain(vector<vector<int>>& pairs) 
    {
        int n = pairs.size();
        int cnt=1;
        int i=1;
        int j=0;
      vector<pair<int,int> >temp;
        for(int i=0;i<n;i++)
        {
            temp.push_back({pairs[i][0],pairs[i][1]});
        }
        sort(temp.begin(),temp.end(),cmp);
        while(i<n)
        {
            if(temp[i].first>temp[j].second)
            {
                cnt++;
                j =i;
                i++;
            }
            else
            {
                i++;
            }
        }
        return cnt;
        
    }
};