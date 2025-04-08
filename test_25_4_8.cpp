class Solution {
public:
    bool _verifyTreeOrder(vector<int>& postorder, int start, int end) 
    {
        if( start >= end) 
        {
            return true;
        }

        int index = start;
        //找到左右子树的分割线
        while (index < end) 
        {
            if (postorder[index] > postorder[end])
                break;

            index++;
        }

        //判断右子树是否满足比根节点大
        int temp = index;
        while (temp < end) 
        {
            if (postorder[temp] < postorder[end])
                return false;

            temp++;
        }
        
        //递归判断左右子树
        bool left=true;
        left = _verifyTreeOrder(postorder, start, index - 1);

        bool right=true;
        right= _verifyTreeOrder(postorder, index, end - 1);

        return (left && right);
    }

    bool verifyTreeOrder(vector<int>& postorder) 
    {
         if (postorder.size() == 0)
          {
            return true;
          }

        return _verifyTreeOrder(postorder, 0, postorder.size() - 1);
    }
};