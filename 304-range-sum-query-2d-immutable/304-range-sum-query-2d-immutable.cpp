class NumMatrix {
public:
    vector<vector<long long > > dp;
    NumMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size()+1;
        int m = matrix[0].size()+1;
        dp = vector<vector<long long int>>(n,vector<long long int>(m,0));
        
        for(int i=1;i<n;i++)
        {
            for(int j=1;j<m;j++)
            {
                dp[i][j] = matrix[i-1][j-1]+dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1];
            }
        }
        
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) 
    {
        int R2 = row2;int C2 = col2;
        int R1 = row1;int C1 = col1;
       
        return (int)(dp[R2+1][C2+1] - dp[R2+1][C1] - dp[R1][C2+1] + dp[R1][C1]);
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */