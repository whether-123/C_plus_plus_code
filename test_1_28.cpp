class MinStack {
public:
    MinStack() {
    }
    
    void push(int val) {
        _st.push(val);
        if(_min.empty()||_min.top()>=val) //加上‘=’ 防止后面有相同的最小值元素入栈
         _min.push(_st.top());            
    }
    
    void pop() {
    if(_min.top()==_st.top()) //_min与_top相等于 _min才能出栈->更新最小值元素
       _min.pop();
       _st.pop();
    }
    
    int top() {
     return _st.top();
    }
    
    int getMin() {
     return _min.top();
    }

    stack<int> _st; //定义两个栈 一个存数据 一个存当前栈中的最小值(保持在栈顶)
    stack<int> _min;
};