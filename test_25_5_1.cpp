class Solution {
public:
    int jewelleryValue(vector<vector<int>>& frame) 
    {
        vector<vector<int>> Maxvalue;
        int rows = frame.size();
        int cols = frame[0].size();

        if (!rows || !cols) 
        {
            return -1;
        }

        Maxvalue.resize(rows,vector<int>(cols));
        
        int up = 0;
        int left = 0;
        for (int i = 0; i < rows; i++) 
        {
            for (int j = 0; j < cols; j++) 
            {
                up = 0;
                left = 0;

                // 行数大于0，才有左边的格子
                if (i > 0) 
                {
                    up = Maxvalue[i - 1][j];
                }
                
                // 列数大于0，才有上边的格子
                if (j > 0) 
                {
                    left = Maxvalue[i][j - 1];
                }

                // 最大值，取上边和左边中的较大值，再加上本格子的值
                Maxvalue[i][j] = max(up, left) + frame[i][j];
            }
        }
        return Maxvalue[rows - 1][cols - 1];
    }
};