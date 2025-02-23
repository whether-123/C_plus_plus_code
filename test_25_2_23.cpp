class Solution {
public:
    bool hasCycle(ListNode *head) {
        
        ListNode* fast=head;
        ListNode* slow=head;
        
        //利用快慢指针 fast每次走两步 slow每次走一步
        //当slow走到环的第一个结点时 设fast与slow相距 x的长度
        //以后每走一次 fast与slow的距离相距会缩短1 
        //x每次 -1 肯定可以减为0 即x=0时 两指针相遇则有环
        while(fast&&fast->next)
        {
            slow=slow->next;
            fast=fast->next->next;

            if(fast==slow)
             return true;
        }
     
        return false;
    }
};