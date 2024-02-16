class Solution {
public:

   TreeNode* _buildTree(vector<int>& preorder, vector<int>& inorder,int begin,int end,int& index)
   {
        if(begin>end)
        return NULL;

        TreeNode* root=new TreeNode(preorder[index]);
        int i=begin;
        while(i<=end)
        {
            if(inorder[i]==preorder[index])
               break;
            else
               ++i;
        }
        //[begin,i-1] i [i+1,end]    //根据中序和先序划分区间 还原二叉树
        if(begin<=i-1)
           root->left=_buildTree(preorder,inorder,begin,i-1,++index);
        else
           root->left=NULL;

        if(i+1<=end)
           root->right=_buildTree(preorder,inorder,i+1,end,++index);
        else
           root->right=NULL;

           return root;
   }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
         int begin=0;
         int end=preorder.size()-1;
         int index=0;    //前序序列中 表示根结点的位置

         return _buildTree(preorder,inorder,begin,end,index);
    }
};