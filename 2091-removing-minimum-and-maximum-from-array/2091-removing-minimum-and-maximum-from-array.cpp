class Solution {
public:
    int minimumDeletions(vector<int>& nums) 
    {
        int n = nums.size();
        
        int minidx =  min_element(nums.begin(),nums.end()) - nums.begin();
        int maxidx =  max_element(nums.begin(),nums.end()) - nums.begin();
        
         if(minidx>maxidx) swap(minidx,maxidx);
        
        return min(maxidx+1 , min(n-minidx , minidx+1+n-maxidx));
        
//         int a = max(minidx,maxidx);
//         int b = min(minidx,maxidx);
        
//         int c = minidx+1 + n-maxidx;
        
       // return min(a,min(b,c));
        
    }
};