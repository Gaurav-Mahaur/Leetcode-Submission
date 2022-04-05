class Solution {
public:
    int maxArea(vector<int>& height) 
    {
        int n = height.size();
        int l=0;
        int r=n-1;
        int a = INT_MIN;
        
        while(l<=r)
        {
            a = max(a,(r-l)*min(height[r],height[l]));
            if(height[l]<height[r])
            {
                l++;
            }
            else
            {
                r--;
            }
        }
        return a;
    }
};