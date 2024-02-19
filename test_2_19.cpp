class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
     vector<int> ret;
     stack<TreeNode*> st;
     TreeNode* tem=root;
     while(tem||!st.empty())
     {
         while(tem)    //当访问到最左结点时 结束
         {
            st.push(tem);
            tem=tem->left;
         }

         TreeNode* top=st.top();
         st.pop();
         ret.push_back(top->val);  //不同于前序遍历 这里访问到最左后再存入val
         tem=top->right;              //取栈顶元素的右子树出来访问
         
     }
    return ret;
    }
};