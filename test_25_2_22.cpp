class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
            ListNode* p=head;
            ListNode* q=head;
            
            //链表长度小于 n 时，返回空
            for(int i=0;i<n;i++)
            {
                if(q!=nullptr)  q=q->next;
                else    return nullptr;
            }
            //链表长度等于 n 时，删除第一个结点
            if(q==nullptr)
            {
                head =head->next;
                delete p;
                return head;
            }
            //链表长度大于 n 时，p走到最后一个结点，删除q的下一个结点
            while(q->next!=nullptr)
            {
                q=q->next;
                p=p->next;
            }

            q=p->next;
            p->next=q->next;
            delete q;

            return head;          
    }
};