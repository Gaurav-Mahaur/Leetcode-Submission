class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) 
    {
        int l1 = abs(ax2-ax1);
        int b1 = abs(ay2-ay1);
        int l2 = abs(bx2-bx1);
        int b2 = abs(by2-by1);
        int area = 0;
        //cout<<l1<<" "<<b1<<endl;
        area += l1*b1 + l2*b2;
        //area += 
        //cout<<area<<endl;
        int left = max(ax1,bx1);
        int bottom = max(ay1,by1);
        int right = min(ax2,bx2);
        int top = min(ay2,by2);
        int common=0;
        if(left<right && top>bottom)
        {
            common = (right-left)*(top-bottom);
        }
        
        int fin = area-common;
        
        return fin;
        
    }
};