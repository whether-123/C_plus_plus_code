class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int>  count;
        //先统计出 <数字，次数>
        for (auto& n : nums)
        {
            count[n]++;
        }
        //创建大小为k的小根堆  反过来存储 <次数，数字>
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> _q;
        for (auto& [n, c] : count)
        {
            if (_q.size() < k)
            {
                _q.push(make_pair(c, n));
            }
            else if (_q.top().first < c)
            {
                _q.pop();
                _q.push(make_pair(c, n));
            }
        }

        //将前个k高频元素 取到数组中返回
        vector<int>  ret(k);
        for (int i = k - 1; i >= 0; i--)
        {
            ret[i] = _q.top().second;
            _q.pop();
        }

        return ret;
    }
};