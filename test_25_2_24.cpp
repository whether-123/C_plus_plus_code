class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* fast=head;
        ListNode* slow=head;
        //通过快慢指针找到相遇的结点 (快指针走两步，慢指针走一步)
        while(fast&&fast->next)
        {
            slow=slow->next;
            fast=fast->next->next;

            if(fast==slow) break;
        }
        //链表不存在环时，返回空指针
        if(fast==nullptr||fast->next==nullptr) return nullptr;
         
        //L=N*C-X  
        //一个指针从相遇点开始走，一个指针从表头开始走
        //一定可以在环形的第一个结点相遇(即要求的结点)
        while(head!=slow)
        {
            head=head->next;
            slow=slow->next;
        }

        return slow;

    }
};