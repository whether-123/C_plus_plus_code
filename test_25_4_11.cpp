class Solution {
public:
    void CloneNodes(Node* head) 
    {
        Node* temp = head;

        // 在每个节点的后面增加一个自己的复制
        while (temp != nullptr) 
        {
            Node* NewNode = new Node(temp->val);
            NewNode->next = temp->next;
            temp->next = NewNode;

            temp = NewNode->next;
        }
    }

    void ConnectRandom(Node* head)
    {
        Node* temp = head;

        // 同步random指针 -- 在Node 和 copyNode之间
        while (temp != nullptr)
        {
            if (temp->random != nullptr) 
            {
                temp->next->random = temp->random->next;
            } 
            temp = temp->next->next;
        }
    }

    Node* ReconnectNodes(Node* head) 
    {
        if (head == nullptr) 
        {
            return head;
        }
        //复制后的链表的首节点
        Node* Newhead = head->next;

        Node* tail = head;
        Node* Newtail = head->next;
        //将节点和复制的节点，拆开
        while (tail != nullptr) 
        {
            tail->next = tail->next->next;
            tail = tail->next;

            if (tail != nullptr) 
            {
                Newtail->next = tail->next;
            }
            Newtail = Newtail->next;
        }
        return Newhead;
    }

    Node* copyRandomList(Node* head) 
    {
        CloneNodes(head);
        ConnectRandom(head);
        return ReconnectNodes(head);
    }
};