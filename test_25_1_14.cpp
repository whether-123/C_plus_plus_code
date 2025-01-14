class Solution {
public:
    int maxProduct(vector<string>& words) {
        int len=words.size();
        vector<int> record(len,0); //记录a~z 映射成二进制的 2^0 2^1 2^2 ... 2^25
        int temp =0;

        for(int i=0;i<len;i++)    //统计每个字符串中 a~z (重复的只统计一次)
        {
            for(int j=0;j<words[i].size();j++)
            {
                record[i]|=1<<(words[i][j]-'a'); //利用或操作(可过滤掉字符串中相同的字符)
            }
        }
          
        for(int i=0;i<len;i++)
        {
            for(int j=i+1; j<len;j++)
            {
               if(!(record[i]&record[j]))  //没有不同字符 则进行比较
                {
                   if((words[i].size()*words[j].size())>temp)
                      temp=words[i].size()*words[j].size();
                }
                  
            }
        }

        return temp;
    }
};