class Solution {
public:
    int evalRPN(vector<string>& tokens) {
      stack<int> st;       //用栈来模拟
      for(auto str:tokens)
      {
          if(str=="+"||str=="-"||str=="*"||str=="/") //操作符则弹出两个数 运算
          {
              int right=st.top();
              st.pop();
              int left=st.top();
              st.pop();

              switch(str[0])
              {
                    case '+':st.push(left+right); //计算完后结果入栈
                    break;
                    case '-':st.push(left-right);
                    break;
                    case '*':st.push(left*right);
                    break;
                    case '/':st.push(left/right);
                    break;
              }       
          }
          else
          {
            st.push(stoi(str)); //整数则入栈 （stoi函数将字符数字转成对应的十进制数字）
          }    
      }

      return st.top(); //循环结束后的栈顶元素即 运算结果
    }
};