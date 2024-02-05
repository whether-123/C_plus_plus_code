class MyQueue {
public:
    MyQueue() { }
    stack<int> st1;  //负责入元素
    stack<int> st2;  //负责倒元素

    void push(int x) {
       st1.push(x); 
    }
    
    void Reverse() //设置子函数 减少代码冗余度
    {
        if(st2.empty())   //st2为空时 才允许入st2
       {
       while(!st1.empty()) //st1不为空时 才允许出st1
       {
           st2.push(st1.top());
           st1.pop();
       }
       }
    }

    int pop() 
    {
       Reverse();
       int temporary =st2.top();
       st2.pop();
       return temporary;
    }
    
    int peek()
    {
       Reverse();
       return st2.top();
    }
    
    bool empty() {
        if(st1.empty()&&st2.empty()) //两个栈同时为空时 模拟的队列为空
        return true;
        else
        return false;
    }
};