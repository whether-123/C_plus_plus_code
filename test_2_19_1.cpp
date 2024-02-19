class Solution {
public:
    TreeNode* _buildTree(vector<int>& inorder, vector<int>& postorder,int begin,int end,int& index)
    {
        if(begin>end)
        return NULL;

        TreeNode* root=new TreeNode(postorder[index]);
        int i=begin;
        while(i<=end)
        {
            if(inorder[i]==postorder[index])
               break;
            else
               ++i;
        }
        //[begin,i-1] i [i+1,end]    //根据后序和先序划分区间 还原二叉树
                                                  //用递归不断划分左右子树
        if(i+1<=end)                   //因为是靠后序确定根的位置 所以先入右子树(靠前序是先入左子树) 
           root->right=_buildTree(inorder,postorder,i+1,end,--index);
        else
           root->right=NULL;

        if(begin<=i-1)               
           root->left=_buildTree(inorder,postorder,begin,i-1,--index);
        else
           root->left=NULL;

           return root;

    } 
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int begin=0;
        int end=inorder.size()-1;
        int index=end;    //代表每个区间中 根结点的位置

        return _buildTree(inorder,postorder,begin,end,index);
    }
};