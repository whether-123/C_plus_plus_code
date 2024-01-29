class Solution {
public:
    bool IsPopOrder(vector<int>& pushV, vector<int>& popV) {
        
        stack<int> st; //利用栈模拟 
        int i=0,j=0;

        while(i<pushV.size())
        {
           st.push(pushV[i]);  //逐步将入栈序列 压入st栈中
           i++;

           while(!st.empty()&&st.top()==popV[j]) //st栈顶元素与出栈元素相同则出
           {
              j++;
              st.pop();
           }
        }

        return st.empty(); //最后st为空 代表匹配成功
    }
};