class Solution {
public:
    string reverseMessage(string message)
    {
        string ret;
        int left = 0;
        int right = message.size()-1;

        while (right >= 0) 
        {
            // 从right开始往左找第一个字符
            while (right >= 0 && message[right] == ' ') 
            {
                right--;
            }

            //没找到字符，则说明左边都是空格，结束循环
            if(right < 0)
            {
                break;
            }

            left = right;
            //基于right的位置，往左找到单词的起始位置
            while (left >= 0 && message[left] != ' ') 
            {
                left--;
            }

            ret += message.substr(left + 1, right - left);
            ret += ' ';

            right = left;
        }

        if(ret.size() != 0)
        {
            //去掉最后一次添加的，多余的一个空格
            ret.pop_back();
        }
        
        return ret;
    }
};