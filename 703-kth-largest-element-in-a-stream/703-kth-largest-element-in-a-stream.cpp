class KthLargest {
public:
    priority_queue<int,vector<int>,greater<int>>pq;
    int m;
    KthLargest(int k, vector<int>& nums) 
    {
        m = k;
        for(int i=0;i<nums.size();i++)
        {
            add(nums[i]);
        }
        
    }
    
    int add(int val) 
    {
        if(pq.size()<m)
        {
            pq.push(val);
        }
        else
        {
            if(val>pq.top())
            {
                pq.pop();
                pq.push(val);
            }
        }
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */