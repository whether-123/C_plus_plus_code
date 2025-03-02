class Solution {
public:
    string replaceSpaces(string S, int length) {
         if(S.size()<1||length<1) return S;
         //统计有多少个空格
         int count=0;
         for(int i=0;i<length;i++)
         {
            if(S[i]==' ') count++;
         }
         //没有空格时
         if(count==0) return S;
         
         //p从url化后的尾部往前走
         //q从url化前的尾部往前走
         int p=length+count*2-1;
         int q=length-1;
         
         //后面的空间足够多 但不一定等于count*2 可能会大于 
         //需要除去后面多余的空间
         S.resize(p+1);
         while(q>-1&&q!=p)
         {
            if(S[q]==' ') 
            {
                S[p--]='0';
                S[p--]='2';
                S[p--]='%';
            }
            else
            {
                S[p]=S[q];
                p--;
            }
            q--;
         }
        return S;
    }
};