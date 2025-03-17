class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int>  count;
        //��ͳ�Ƴ� <���֣�����>
        for (auto& n : nums)
        {
            count[n]++;
        }
        //������СΪk��С����  �������洢 <����������>
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

        //��ǰ��k��ƵԪ�� ȡ�������з���
        vector<int>  ret(k);
        for (int i = k - 1; i >= 0; i--)
        {
            ret[i] = _q.top().second;
            _q.pop();
        }

        return ret;
    }
};