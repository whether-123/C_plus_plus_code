class Solution {
public:
    void ConvertList(TreeNode* cur,TreeNode*& prev)
	{
		if(cur==NULL)
		   return;

		ConvertList(cur->left,prev);	 
		 
		cur->left=prev;         //当前结点的左指向前一个
		
		if(prev)                      //我不知道当前结点的下一个是谁？但我知道当前结点的上一个
		   prev->right=cur;  //上一个结点的右指向当前结点

		prev=cur;

		ConvertList(cur->right,prev);
	}
    TreeNode* Convert(TreeNode* pRootOfTree) {

		TreeNode* prev=NULL;          //表示当前结点的上一个结点
		ConvertList(pRootOfTree,prev);

		TreeNode* head=pRootOfTree; 
		while(head && head->left)   //找到中序遍历的起始结点
		    head=head->left;     

		return head; 
    }
};
