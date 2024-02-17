class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
       vector<int> ret;
       stack<TreeNode*> st;
       TreeNode* tem=root;
       while(tem||!st.empty())      //先访问左路结点 再访问左路结点的右子树
       {
           while(tem) 
           {
               ret.push_back(tem->val);
               st.push(tem);
               tem=tem->left;
           }

           TreeNode* top =st.top();
           st.pop();
           tem=top->right;        //取出栈顶结点的右子树出来访问
       }

       return ret;
    }
};