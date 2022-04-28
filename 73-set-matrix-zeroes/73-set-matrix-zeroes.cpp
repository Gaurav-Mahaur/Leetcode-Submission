class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) 
    {
        int n = matrix.size();
        int m = matrix[0].size();
        
        int  f=0;
        int s=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(matrix[i][j]==0)
                {
                    if(i==0)
                    {
                        f=1;
                    }
                    if(j==0)
                    {
                        s=1;
                    }
                    matrix[i][0]=0;
                    matrix[0][j]=0;
                }
            }
        }
        for(int i=1;i<n;i++)
        {
            for(int j=1;j<m;j++)
            {
                if(matrix[i][0]==0||matrix[0][j]==0)
                {
                    matrix[i][j]=0;
                }
            }
        }
        if(f==1)
        {
            for(int i=0;i<m;i++)
            {
                matrix[0][i]=0;
            }
        }
        if(s==1)
        {
            for(int i=0;i<n;i++)
            {
                matrix[i][0]=0;
            }
        }
        
    }
};