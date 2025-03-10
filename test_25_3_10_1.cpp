class Solution {
public:
    void _sumNumbers(TreeNode* root,int& _sum,int num)
    {
         if(root==nullptr)   return;
         
         //利用前序遍历的思想  从根节点往下求 num
         num+=root->val;

        if(root->left!=nullptr) 
          _sumNumbers(root->left,_sum,num*10);

        if(root->right!=nullptr) 
          _sumNumbers(root->right,_sum,num*10);
        
        //利用后序遍历的思想  走到叶节点时  将num到_sum中
        if(root->left==nullptr&&root->right==nullptr)
         _sum+=num;

    }

    int sumNumbers(TreeNode* root) {
        
        int sum=0;
       _sumNumbers(root,sum,0);

        return sum;
    }
};