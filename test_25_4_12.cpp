class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) 
    {
        string str;
        _serialize(root, str);
    //利用前序遍历的顺序，序列化
        return str;
    }

    void _serialize(TreeNode*& root, string& s)
    {
        //用 # 代替空 , 为分隔符
        if (root == nullptr) 
        {
            s += "#,";
            return;
        }

        s += to_string(root->val);
        s += ',';

        _serialize(root->left, s);
        _serialize(root->right, s);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) 
    {
        int index = 0;
        //利用前序遍历，构建二叉树，反序列化
        return _deserialize(data, index);
    }

    TreeNode* _deserialize(string& data, int& index) 
    {
        if (index >= data.size()) 
        {
            return nullptr;
        }

        if (data[index] != '#') 
        {
            //因为数字可能占多位
            int end = index;
            while (end<data.size()) 
            {
                if (data[end] == ',')
                    break;
                end++;
            }

            string Snumber = data.substr(index, end - index);
            int number = stoi(Snumber);

            TreeNode* pNode = new TreeNode(number);
            pNode->left = nullptr;
            pNode->right = nullptr;

            //传入的下一个位置
            index = end + 1;
            pNode->left = _deserialize(data, index);
            //左子树结束，一定是遇到了# 加2跳过 "#,"
            index += 2;
            pNode->right = _deserialize(data, index);

            return pNode;
        }
        return nullptr;
    }
};