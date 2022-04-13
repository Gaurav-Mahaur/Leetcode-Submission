class Solution {
public:
    vector<vector<int>> generateMatrix(int n) 
    {
        vector<vector<int> > ans(n,vector<int>(n));
        int r1=0;
        int r2=n-1;
        int c1=0;
        int c2=n-1;
        int val=0;
        
        while(r1<=r2 && c1<=c2)
        {
            //left to right
            for(int i=c1;i<=c2;i++)
            {
                ans[r1][i] = ++val;
            }
            //top to bottom
            for(int i=r1+1;i<=r2;i++)
            {
                ans[i][c2] = ++val;
            }
            if(r1 < r2 && c1 < c2)
            {
                // move right to left (row will be fixed)
                for(int i = c2-1; i>c1; --i)
                    ans[r2][i] = ++val;
					
					// move up (col will be fixed)
					for(int i = r2; i>r1; --i) 
                    ans[i][c1] = ++val;
            }
            r1++;
            r2--;
            c1++;
            c2--;
        }
        
        return ans;
        
    }
};