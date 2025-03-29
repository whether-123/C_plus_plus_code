class Solution {
public:
    bool _isSubStructure(TreeNode* A, TreeNode* B) {

        if (B == nullptr)
            return true;

        if (A == nullptr)
            return false;
        //依次向下比较，左右子树的比较都为真时，返回真
        if (A->val == B->val) 
        {
            bool isLeft = _isSubStructure(A->left, B->left);
            bool isRight = _isSubStructure(A->right, B->right);
            return isLeft && isRight;
        }
        
        return false;
    }

    bool isSubStructure(TreeNode* A, TreeNode* B) 
    {
        if (A == nullptr || B == nullptr)
            return false;

        //寻找A中节点与B的根节点，val相同
        if (A->val == B->val) 
        {   
            //以A中此节点与B相比，B是否为A的子树
            if (_isSubStructure(A, B)) 
            {
                return true;
            }
        }

        bool isLeft = isSubStructure(A->left, B);
        bool isRight = isSubStructure(A->right, B);

        return isLeft || isRight;
    }
};