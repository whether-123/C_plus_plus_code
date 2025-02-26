class Solution {
public:
    void reorderList(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head;
        //找到链表的中点
        while(fast!=nullptr&&fast->next!=nullptr)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        //按中点将链表断开       
        ListNode* newhead=nullptr;
        ListNode* q=slow->next;
        slow->next=nullptr;
        slow=q;
        //反转后半段链表
        while(slow!=nullptr)
        {
           slow=slow->next;
           q->next=newhead;
           newhead=q;
           q=slow;
        }
        //将后半段链表插入前半段链表
        q=head;
        ListNode* p=newhead;
        while(newhead!=nullptr)
        {
          newhead=newhead->next;
          p->next=q->next;
          q->next=p;
          q=p->next;
          p=newhead; 
        }
    }
};