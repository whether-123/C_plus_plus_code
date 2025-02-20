class Solution {
public:
    //判断所传入的区间是否为回文
    bool isPalindrome(int _left,int _right,const string &_s)
    {
        while(_left<_right)
        {
            if(_s[_left]==_s[_right])
            {
                _left++;
                _right--;
            }
            else  return false;
        }
        
        return true;
    }
    bool validPalindrome(string s) {
        int left=0,right=s.size()-1;

        while(left<right)
        {
            if(s[left]==s[right])
            {
                left++;
                right--;
            }  
            else //当遇到不相等时，判断[左指针+1,右指针]，[左指针,右指针-1]
                 //来模拟删除左指针指向的字符 or 右指针指向的字符
            return isPalindrome(left+1,right,s)||isPalindrome(left,right-1,s);    
        }

        return true;
    }
};