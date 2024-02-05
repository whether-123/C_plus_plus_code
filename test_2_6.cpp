class MyStack {
public:
    MyStack() {  }
    queue<int> q1; //入元素
    queue<int> q2; //倒元素

    void push(int x) 
    {
     q1.push(x);
    }
    
    void Reverse()  //设置子函数，减少代码冗余量
    {
     if(q1.size()==0)
        swap(q1,q2);    //q1为空->交换q1 q2 即默认q2的作用是倒元素 q1的作用是入元素
     while(q1.size()>1)
      {
         q2.push(q1.front());
         q1.pop();
      }
    }

    int pop() 
    {
     Reverse();
      int temporary=q1.front();
      q1.pop();
      return temporary;
    }
    
    int top() 
    {
    Reverse();
      return q1.front();
    }
    
    bool empty() {
      if(q1.empty()&&q2.empty())
      return true;
      else
      return false;
    }
};