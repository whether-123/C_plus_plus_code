class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int len=temperatures.size();
        vector<int> ret(len,0);
        //用数组模拟栈，栈中存储元素的下标
        vector<int> st;
        
        for(int i=0;i<len;i++)
        {   
            //栈不为空 且当前温度值高于栈顶温度值
            while(!st.empty()&&temperatures[i]>temperatures[st.back()])
            {
                // 出栈，并存储需要等待的天数
                ret[st.back()]=i-st.back();
                st.pop_back();
            }
            //栈中没有比我低的温度 入栈
            st.push_back(i);
            //如果没有比我高的温度 就不会出栈，使用默认值0
        }
        
        return ret;       
    }
};