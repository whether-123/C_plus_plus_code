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

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
       //先反转链表
       ListNode* newl1=reverseList(l1);
       ListNode* newl2=reverseList(l2);
       ListNode* newl3=nullptr;
       ListNode* p=nullptr;
       int temp=0;

       //从个位开始加，直到其中一个链表走到空
       while(newl1!=nullptr&&newl2!=nullptr)
       {
         temp+=(newl1->val+newl2->val);
         if(temp>9)
         {
            p= new ListNode(temp%10);
            temp/=10;
         }
         else
         {
            p= new ListNode(temp);
            temp=0;
         }
         p->next=newl3;
         newl3=p; 
         newl1=newl1->next;
         newl2=newl2->next;

       }
        
        //哪个链表不为空 接着开始加(和temp一起)
        while(newl2!=nullptr)
        {
            temp+=newl2->val;
            if(temp>9)
            {
              p= new ListNode(temp%10);
              temp/=10;
            }
            else
            {
              p= new ListNode(temp);
              temp=0;
            }
             p->next=newl3;
             newl3=p; 
             newl2=newl2->next;
        }
     
        while(newl1!=nullptr)
        {
            temp+=newl1->val;
            if(temp>9)
            {
              p= new ListNode(temp%10);
              temp/=10;
            }
            else
            {
              p= new ListNode(temp);
              temp=0;
            }
             p->next=newl3;
             newl3=p; 
             newl1=newl1->next;
        }
       
       //当两个链表都走到空时 temp存储的是进位
       if(temp!=0)
       {
           p= new ListNode(temp);
           p->next=newl3;
           newl3=p; 
       }

       return newl3;
    }
};