class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
             vector<vector<int>> vv;
             queue<TreeNode*> q;

              if(root)
                q.push(root);
            
            while(!q.empty())
            { 
                int levelSize=q.size();  //记录每一层的结点个数
                vector<int> v;

                for(size_t i=0;i<levelSize;i++) //控制数据一层一层的入
                {
                  TreeNode* _front=q.front();
                  q.pop();
                  v.push_back(_front->val);
            
                  if(_front->left)
                    q.push(_front->left);
                  if(_front->right)
                    q.push(_front->right);
                }

                vv.push_back(v);  //入完一层后 存入vv中
            }

            reverse(vv.begin(),vv.end());   //vector里的逆置函数
            return vv;
    }
};        
    