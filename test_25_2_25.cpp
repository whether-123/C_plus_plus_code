class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* temp=head;
        ListNode* newhead=nullptr;

        //将原链表的结点依次 头插到新链表中
        while(head!=nullptr)
        {
            head=head->next;
            temp->next=newhead;
            newhead=temp;
            temp=head;
        }

        return newhead;
    }
};