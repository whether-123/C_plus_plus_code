class Solution {
public:                 
    bool IsChar(char ch)//判断是否为字母(大写/小写)
    {
        if((ch>='a'&&ch<='z')||(ch>='A'&&ch<='Z'))
              return true;
        else
              return false;
    }
    string reverseOnlyLetters(string s) {
       
        int begin=0,end=s.size()-1; //利用快排的思想，从两边往中间遍历
       
        while(begin<end) //当begin>=end时意为遍历结束
        {
            while(begin<end&&!IsChar(s[end]))//遇到不是字母时移动
            --end;
            while(begin<end&&!IsChar(s[begin]))
            ++begin;

            swap(s[begin],s[end]);//swap模板函数直接用
            --end;
            ++begin;
        }

            return s;
    }
};