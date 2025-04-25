class LRUCache 
{
public:
    //双向链表节点
    struct ListNode 
    {
        int _key;
        int _value;

        ListNode* _prev;
        ListNode* _next;

        ListNode(int key = -1, int value = -1)
            : _key(key), _value(value), _prev(nullptr), _next(nullptr) {}
    };
                  
    int _capacity; //LURcache的大小
    int _size;     //实际存储元素个数
    unordered_map<int, ListNode*> Hash; //哈希表用于o(1)查找
    ListNode* head; //双向链表头结点

    LRUCache(int capacity) 
    {
        _capacity = capacity;
        _size = 0;
        head = new ListNode();
        head->_prev = head;
        head->_next = head;
    }

    //更新节点到表头(表示最近被访问的节点优先级最高)
    void UpdateNode(ListNode* temp) 
    {
        temp->_prev = head;
        temp->_next = head->_next;
        head->_next->_prev = temp;
        head->_next = temp;
    }

    int get(int key) 
    {
        unordered_map<int, ListNode*>::iterator it = Hash.find(key);
        //不存在
        if (it == Hash.end()) 
        {
            return -1;
        }
        
        ListNode* temp = it->second;
        if (temp == head->_next) 
        {
            return temp->_value;
        }
        
        //存在，将其更新到表头
        ListNode* prevNode = temp->_prev;
        ListNode* nextNode = temp->_next;

        prevNode->_next = nextNode;
        nextNode->_prev = prevNode;
        UpdateNode(temp);

        return temp->_value;
    }

    void put(int key, int value)
    {
        ListNode* temp = nullptr;
        unordered_map<int, ListNode*>::iterator it = Hash.find(key);
        //如果存在，更新value值，并将其移动到表头
        if (it != Hash.end()) 
        {
            it->second->_value = value;
            temp = it->second;
            if (temp == head->_next) 
            {
                return;
            }

            ListNode* prevNode = temp->_prev;
            ListNode* nextNode = temp->_next;

            prevNode->_next = nextNode;
            nextNode->_prev = prevNode;
            UpdateNode(temp);
        } 
        //不存在，创建节点，插入到表头
        else 
        {
            temp = new ListNode(key, value);
            UpdateNode(temp);
            Hash.insert(make_pair(key, temp));
            _size++;
            
            //实际大小大于容量时，删除最久未访问的节点
            if (_size > _capacity)
            {
                ListNode* delNode = head->_prev;
                delNode->_next->_prev = delNode->_prev;
                delNode->_prev->_next = head;

                delNode->_prev = nullptr;
                delNode->_next = nullptr;
                Hash.erase(delNode->_key);

                delete delNode;
                _size--;
            }
        }
    }
};
