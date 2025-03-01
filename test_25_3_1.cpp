class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
         vector<int> temp;
         for(auto ast:asteroids)
         {
            bool flag=true;
            //当栈顶元素＞0 且 ast ＜0 时 才有可能发生碰撞
            //当ast 被碰撞没了 或者 栈顶元素<0 /栈为空 结束循环
            while(flag&&ast<0&&!temp.empty()&&temp.back()>0)
            {
                //5 -5 碰撞都消失
                if(-ast==temp.back()) 
                {
                    flag=false;
                    temp.pop_back();
                } 
                //5 -3 ast碰撞消失
                else if(-ast<temp.back()) 
                {
                    flag=false;
                }
                else //3 -5  栈顶元素碰撞消失，且ast继续与栈顶元素发生碰撞
                {
                    temp.pop_back(); 
                }
            }
            //ast 没有消失 则入栈
            if(flag) 
            temp.push_back(ast);
         }

         return temp;
    }
};