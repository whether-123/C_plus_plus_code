class Solution {
public:
    string tree2str(TreeNode* root) {
        string str;
        if(root==NULL)
        return str;

        str+=to_string(root->val); //将整型数字转化成字符数字
        if(root->left)
        {
            str+='(';
            str+=tree2str(root->left);
            str+=')';
        }
        else if(root->right) //左为空 右不为空时输出() -> 表示左子树为空
        {
            str+="()";
        }

        if(root->right)
        {
            str+='(';
            str+=tree2str(root->right);
            str+=')';
        }

        return str;
    }
};