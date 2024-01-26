class Solution {
public:
    vector<vector<int>> generate(int numRows) {
     vector<vector<int>> number;
     number.resize(numRows);   //借用resize动态开辟空间并初始化为默认值
     for(int i=0;i<numRows;i++)
     {
         number[i].resize(i+1); 

         number[i][0]=1;     //将每行第一个和最后一个赋值为1
         number[i][number[i].size()-1]=1;
     }

     for(int j=2;j<numRows;j++)
     {
         for(int i=1;i<number[j].size()-1;i++)
         {                                      //利用杨辉三角的性质
                                                //每个数是它左上方和右上方的数的和
             number[j][i]=number[j-1][i-1]+number[j-1][i];
         }
     }
      
      return number;
    }
};