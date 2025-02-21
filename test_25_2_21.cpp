class Solution {
public:
    int countSubstrings(string s) {
        int len=s.size();
        int left=0,right=0;
        int count=0;
        //可能的回文中心 从左往右依次枚举
        //[0,0] [0,1] [1,1] [1,2] .....[len-1,len-1]
        while(!(right==len)) //走完[len-1,len-1]后结束循环 
        {
            int i=left,j=right;
            //从回文中心往两边扩展去统计 回文子串
            while(i>-1&&j<len)
            {
                if(s[i]==s[j])
                {
                    i--;
                    j++;
                    count++;
                }
                else
                break;
            }
            //初始时 [0,0] 往后每趟右指针先走一次，然后下一趟左指针再走一次
            if(left==right) right++;
            else  left++;
        }
        
        return count;
    }
};