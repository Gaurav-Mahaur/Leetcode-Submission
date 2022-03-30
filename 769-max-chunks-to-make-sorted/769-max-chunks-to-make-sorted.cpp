class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) 
    {
        int n =arr.size();
        
        int cnt=0;
        int maxx = 0;
        for(int i=0;i<n;i++)
        {
            maxx = max(maxx,arr[i]);
            if(maxx==i)
            {
                cnt++;
            }
        }
        return cnt;
    }
};