class sum{
public:
    sum()
    {
        _sum+=_i;
        _i++;
    }
   static int Print()
  {
    return _sum;
  }
   static void Init()
  {
    _i=1;
    _sum=0;
  }     
private:
  static int _i;
  static int _sum;
};
int sum::_i=1;
int sum::_sum=0;

class Solution {
public:
    int Sum_Solution(int n) {
        sum::Init();//多个测试用例，每次进入将_i _sum重置为初始值
        sum A[n];//利用类定义对象，需要调用构造函数的性质

       return sum::Print();//静态成员函数 不用对象 仅类名加作用域就可在类外访问
 }
};