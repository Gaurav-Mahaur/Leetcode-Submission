class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) 
    {
        int n = heights.size();
        if(n==1)
        {
            return 0;
        }
        
        priority_queue<int,vector<int>,greater<int>>pq;
        int i=0;
        for(i=0;i<n-1;i++)
        {
            int h = heights[i+1]-heights[i];
            if(h<=0)
            {
                continue;
            }
            pq.push(h);
            
            if(pq.size()>ladders)
            {
                bricks -= pq.top();
                pq.pop();
                
                if(bricks<0)
                {
                    //k =i;
                    break;
                }
            }
        }
        return i;
        
    }
};