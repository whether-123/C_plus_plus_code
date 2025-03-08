class Solution {
public:
     void depth_first(TreeNode* root ,int high ,vector<int>& temp )
     {
        //前序遍历 根左右 
        //进入每一层记录高度
        if(!(high<temp.size())) 
        {
            //先访问根节点 方便处理temp
            temp.push_back(root->val);
        }
        else if(root->val>temp[high])
        {
            temp[high]=root->val;
        }
        //左子树
        if(root->left!=nullptr)  
        {
            depth_first(root->left,high+1,temp);
        }        
        //右子树
        if(root->right!=nullptr)  
        {
            depth_first(root->right,high+1,temp);
        }
     }
    vector<int> largestValues(TreeNode* root) {
          vector<int> ret;
          if(root==nullptr)  
          {
            return ret;
          }
          //深度优先遍历
          depth_first(root,0,ret);
          return ret; 
     }
};