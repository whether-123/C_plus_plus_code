#include"process.h"

char style[S_NUM]={'|','!','#','&','@'};

void ProncessOn() //函数的定义
{
    int cnt=0;
    char bar[NUM];
    memset(bar,'\0',sizeof(bar));

    //reverse
    const char *lable="|\\-/";

    //101 times
    while(cnt<=100)
   {
        printf("\033[40;33m[%-100s][%d%%][%c]\r",bar,cnt,lable[cnt%4]);
        fflush(stdout);
        bar[cnt++]=style[N];
        //slepp(1);
        usleep(50000); //5S/100 == 0.05S == 5000
    }

    printf("\n");
}
