class Trie {
private:
    //哈希表映射
    vector<Trie*> word_hash;
    bool is_end;

    Trie* search_min(string& word) 
    {
        Trie* node = this;
        for (auto w : word) 
        {
            //如果不存在，说明没有
            if (node->word_hash[w - 'a'] == nullptr) 
            {
                return nullptr;
            }
            node = node->word_hash[w - 'a'];
        }
        return node;
    }

public:
  
    Trie() : word_hash(26), is_end(false) {}

    //插入单词
    void insert(string& word) 
    {
        Trie* node = this;

        for (char w& : word) 
        {
            if (node->word_hash[w - 'a'] == nullptr) 
            {
                node->word_hash[w - 'a'] = new Trie();
            }
            // 结束循环时 node指向结尾的字母
            node = node->word_hash[w - 'a'];
        }
        // 定义结束标志
        node->is_end = true;
    }

    //搜索单词是否存在
    bool search(string& word)
    {
        Trie* node = search_min(word);
        //单词存在且 该位置是结尾
        return node != nullptr && node->is_end;
    }

    //搜索是否为某单词的前缀
    bool startsWith(string& prefix) 
    {
        Trie* node = search_min(prefix);
        return node != nullptr;
    }
};
