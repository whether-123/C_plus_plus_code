class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) 
    {   
        //list1先走完，返回list2
        if (list1 == nullptr) 
        {
            return list2;
        }
        //list2先走完，返回list1
        if (list2 == nullptr) 
        {
            return list1;
        }

        ListNode* newHead;
        if (list1->val < list2->val) 
        {
            newHead = list1;
            newHead->next = mergeTwoLists(list1->next, list2);
        } 
        else 
        {
            newHead = list2;
            newHead->next = mergeTwoLists(list1, list2->next);
        }

        return newHead;
    }
};