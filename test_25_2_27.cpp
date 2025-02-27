class Solution {
public:
    Node* insert(Node* head, int insertVal) {
        Node* temp=new Node(insertVal);
        //链表为空时
        if(head==nullptr) 
        {
            temp->next=temp;  
            head=temp;
            return head;
        }
        
        //链表的结点≥1时
        Node* cur=head;
        Node* _next=head->next;
        //将链表从head位置遍历一遍
        //如果遍历一圈还没有满足情况，那么一定是插入在head的上一个位置(即结束循环时的位置)
        while(_next!=head)
        {   
            //在中间位置找到
            if(insertVal>=cur->val&&insertVal<=_next->val)
            {
                break;
            }
            //当cur为最大结点，_next为最小结点时
            if(cur->val>_next->val)
            {
                //要插入的insertVal 为最小或最大时 插入的位置都是cur和_next之间
                if(insertVal>cur->val || insertVal<_next->val)
                 {
                    break;
                 }
            }
            //都不满足，继续往下找
            cur=cur->next;
            _next=_next->next;
        }
        //当链表只有一个结点时，不会进入循环
        cur->next=temp;
        temp->next=_next;
        return head;
    }
};