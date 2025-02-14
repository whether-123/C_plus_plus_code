class NumMatrix {
public:
    NumMatrix(vector<vector<int>>& matrix) {
        int row=matrix[0].size();  //记录行数
        int col=matrix.size();     //记录列数

        psum.resize(col+1);
        
        psum[0].resize(row+1);
        for(int i=1;i<=col;i++)
        {
            psum[i].resize(row+1); //初始化第i列 值为0
            for(int j=1;j<=row;j++)
            {
                //创建[row+1][col+1]  并将 0行和0列的元素置为0  
                //1~row 1~col 存储相对于 [1][1]的前缀和 
                //预留出的一行一列 -> 可减少求和时的边界条件判断
                psum[i][j]=psum[i-1][j]+psum[i][j-1]+matrix[i-1][j-1]-psum[i-1][j-1];

            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        //根据初始化好的二维数组的前缀和 直接相加减得到子数组的和
        int sum=psum[row2+1][col2+1]-psum[row2+1][col1]-psum[row1][col2+1] + psum[row1][col1];
        return sum;
    }

private:
    vector<vector<int>>  psum; 
};