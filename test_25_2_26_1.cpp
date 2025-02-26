class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(head==nullptr) return false; 
        //将链表的数据存入数组中
        vector<int> temp;
        ListNode* p=head;
        while(p!=nullptr)
        {
            temp.push_back(p->val);
            p=p->next;
        }
        //在数组中进行判断
        int i=0;
        int j=temp.size()-1;
        while(i<j)
        {
            if(temp[i]!=temp[j]) 
                return false;
            i++;
            j--;
        }

        return true;
    }
};