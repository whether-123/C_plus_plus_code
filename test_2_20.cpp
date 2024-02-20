class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
     vector<int> ret;
     stack<TreeNode*> st;
     TreeNode* lastNode=NULL;   //最近访问的结点
     TreeNode* tem=root;

     while(tem||!st.empty())
     {
         while(tem)       //  入栈取到最左结点
         {
             st.push(tem);
             tem=tem->left;
         }
         
         //如果左路结点的右为空或者上一个最近访问结点是右子树的根，则表示右子树已经访问过了
         //就可以访问这个结点了  否则迭代访问右子树
         TreeNode* top=st.top();
         if(top->right==NULL||lastNode==top->right)
         {
             ret.push_back(top->val);
             lastNode=top;
             st.pop();
         }
         else
         {
             tem=top->right;
         }
     }
     return ret;
    }
};