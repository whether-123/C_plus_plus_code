class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        //lambad表达式 实现两个数组中 数对和的比较
        auto cmp = [&nums1, &nums2](pair<int, int> a,pair<int, int> b) -> bool
        {
            return nums1[a.first] + nums2[a.second] >  nums1[b.first] + nums2[b.second];
        };
        //传入自定义比较方式
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)>  min_heap(cmp);

        int nums1_len = nums1.size();
        int nums2_len = nums2.size();
        //可变参数
        min_heap.emplace(0, 0);
        vector<vector<int>> ret;
        
        //按层入节点 
        //[0,0]
        //[1,0] [0,1]
        //[2,0] [1,1] [0,2]
        while (k-- && !min_heap.empty()) {
            
            auto [first,second] = min_heap.top();
            min_heap.pop();
            //存入数对
            ret.emplace_back(initializer_list<int>{nums1[first],nums2[second]});

            // 当前节点为[first,0] 还需放入节点[first+1,0]
            if (second == 0 && first + 1 < nums1_len) {
                min_heap.emplace(first + 1, 0);
            }

            // 放入后续节点[first,second+1]
            if (second + 1 < nums2_len) {
                min_heap.emplace(first, second + 1);
            }
        }

        return ret;
    }
};