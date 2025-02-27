class Solution {
public:
    Node* flatten(Node* head) {
        // 定义三个指针
        // 当cur的child不为空时 _next保存cur->next
        // child_tail用于寻找child的尾结点
        Node* cur = head;
        Node* _next = nullptr;
        Node* child_tail = nullptr;

        // 自上而下的扁平化
        for (; cur != nullptr; cur = cur->next) {
            // child为空时 cur往后走
            if (cur->child == nullptr)
                continue;
            // child不为空时 _next保存cur->next child_tail用于寻找child的尾结点
            _next = cur->next;
            cur->child->prev = cur;
            cur->next = cur->child;
            cur->child = nullptr;
            child_tail = cur->next;

            while (child_tail->next != nullptr)
                child_tail = child_tail->next;

            // 找到后 将child_tail与 _next 连接起来
            child_tail->next = _next;
            // 注意边界，万一cur为上一级链表的尾结点
            if (_next != nullptr)
                _next->prev = child_tail;
        }

        return head;
    }
};