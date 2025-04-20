class Solution {
public:
    int _digitOneInNumber(const char* Snum)
    {
        if(Snum==nullptr||*Snum<'0'||*Snum>'9'||*Snum=='\0')
        {
            return 0;
        }

        int Topdigit=*Snum-'0';
        size_t size=strlen(Snum);
        
        if(size==1&&Topdigit==0)
        {
            return 0;
        }

        if(size==1&&Topdigit>0)
        {
            return 1;
        }

        //走到这里最少有两位
        //统计最高位为1的情况
        int Topcount=0;
        if(Topdigit>1)
        {
           Topcount=numcount(size-1);
        }
        else if(Topdigit==1)
        {
           Topcount=atoi(Snum+1)+1;
        }
        //统计次高位和个位为1的情况
        int Othercount=Topdigit*(size-1)*numcount(size-2);
        
        //拆分 -- 统计 (原数字~去掉最高位的原数字) 之间1出现的情况
        //剩下的 (去掉最高位的原数字-1) 递归子问题解决
        return Topcount+Othercount+_digitOneInNumber(++Snum);
    }
    
    int numcount(size_t n)
    {
        int ret=1;
        for(size_t i=0;i<n;i++)
        {
            ret*=10;
        }

        return ret;
    }

    int digitOneInNumber(int num) {
        
        char *temp=new char[12];
        sprintf(temp,"%d",num);

        return _digitOneInNumber(temp);
    }
};