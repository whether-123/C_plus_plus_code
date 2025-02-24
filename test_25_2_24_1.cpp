class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        ListNode* p=headA;
        ListNode* q=headB;
        int len_A=0,len_B=0;

        //统计每个链表的长度
        while(p!=nullptr)
        {
            len_A++;
            p=p->next;  
        }

          while(q!=nullptr)
        {
            len_B++;
            q=q->next;  
        }

        int temp=len_A-len_B;
        int flag=0;
        if(temp<0)
        {
            flag=1;
            temp=-temp;
        }
        
        //让长的链表，先走 两个链表的差值
        p=headA;
        q=headB;
        while(temp--!=0)
        {
            if(flag==0) p=p->next;
            else q=q->next;
        }
        
        //然后再一起走，相遇点即交点
        //如果两个链表没有交点，会一起走到空(返回空指针)
        while(p!=q)
        {
           p=p->next;
           q=q->next; 
        }
        return p;
    }
};