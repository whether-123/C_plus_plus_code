class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) { 
        unordered_map<int,int> count;  //存入并统计次数 KV模型
        for(auto number : nums1)
        {
            count[number]++;
        }

        vector<int> ret;
        for(auto number : nums2)
        {
            unordered_map<int,int>::iterator it=count.find(number);
           if(it != count.end())     //find() 查找失败 返回end()   
            {
                if(it->second>0)     //元素存在 且次数>0 才能入
                {
                    ret.push_back(number);
                    it->second--;
                }
                
            }
        }
        return ret;
    }
};