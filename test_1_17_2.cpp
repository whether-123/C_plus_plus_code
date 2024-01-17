#include <iostream>
using namespace std;

int main() {
    int year,month,day;

    //这样可以不断接受输入，直到按ctrl + c 就结束
    while (cin >>year>>month>>day) {
        
        int GetMonday[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};

        int n=0;

        //累加[1,month-1]月的天数
        for(int i=1;i<month;i++)
        {
            n+=GetMonday[i];
        }
            n+=day;

        //如果是闰年 2月份补一天
        if(month>2&&((year%4==0&&year%100!=0)||year%400==0))
        {
            n++;
        }
        cout<<n<<endl;
    }
    return 0;
}