class Solution {
public:
    bool Find(TreeNode* root,TreeNode* tmp)   //find 函数 找到返回true 否则返回false
    {
        if(root==NULL)
        return false;
        return root==tmp||Find(root->left,tmp)||Find(root->right,tmp);
    } 
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL) return NULL;
        if(root==q||root==p) return root;

        bool pInLeft,pInRight,qInLeft,qInRight;
         pInLeft=Find(root->left,p);
         pInRight=!pInLeft;
         qInLeft=Find(root->left,q);
         qInRight=!qInLeft;

         if((pInLeft && qInRight)||(qInLeft && pInRight))   //p在左q在右 或 q在左q在右 时根节点为最近祖宗
          return root;

          if(pInLeft && qInLeft)          //p q都在左时 递归进左子树 找最近祖宗
          return lowestCommonAncestor(root->left,p,q);

          if(pInRight && qInRight)   //p q都在右时 递归进右子树 找最近祖宗
          return lowestCommonAncestor(root->right,p,q);

          return NULL;
    }
};