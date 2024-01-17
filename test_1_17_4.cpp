class Solution {
public:
    
    bool IsCharOrNumber(char ch)
    {
        if((ch>='a'&&ch<='z')||(ch>='0'&&ch<='9'))
            return true;
        else
            return false;  
    }

    bool isPalindrome(string s) {
       
        for(int i=0;i<s.size();i++) //将大写字母转成小写字母
        {
            if(s[i]>='A'&&s[i]<='Z')
            s[i]+=32;
        }
        
        int begin=0,end=s.size();

        while(begin<end) //从两边往中间遍历，遇到非字母数字字符跳过
        {
            while(begin<end&&!IsCharOrNumber(s[end]))
              --end;
            while(begin<end&&!IsCharOrNumber(s[begin]))
              ++begin;

              if(s[begin]!=s[end])
              return false;

              --end;
              ++begin;        
        }
              return true;

    }
};