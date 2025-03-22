class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return head;
            
        ListNode* pPre=nullptr;
        ListNode* pNode=head;
        ListNode* pNext=nullptr;
        
        //外层循环控制pNode往后走
        while(pNode!=nullptr)
        {
           pNext=pNode->next;
           bool needDelete=false;
           //设置一个标志位 判断是否为重复节点 需要删除
           if(pNext!=nullptr&&pNext->val==pNode->val)
           {
                needDelete=true;
           }
           //不为重复节点时
           if(!needDelete)
           {
             //这里面不能移动pNext
             //怕万一pNode是尾节点 
             //在循环开头移动pNext
             pPre=pNode;
             pNode=pNode->next;
           }
           else //重复节点
           {
             int value=pNode->val;
             ListNode* temp=pNode;
             //内层循环控制删除重复节点
             while(temp!=nullptr&&temp->val==value) 
             {
                delete temp;
                temp=nullptr;
                temp=pNext;
                if(pNext!=nullptr)
                pNext=pNext->next;
             }
             //删除重复节点后，将链表连接起来
             if(pPre!=nullptr)
             {
                pPre->next=temp;
             }
             else //一开始就是重复的元素
             {
                head=temp;
             }
              pNode=temp;
           }
        } 
        return head;
    } 
};