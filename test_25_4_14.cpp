class MedianFinder {
public:
    priority_queue<int, vector<int>, greater<int>> minheap; // 用小堆记录右边的数
    priority_queue<int> maxheap; // 用大堆记录左边的数

    MedianFinder() {}

    void addNum(int num) 
    {
        
        size_t len = minheap.size() + maxheap.size();
        //这样插入保证了大堆和小堆相差长度不超过1
        // 长度为奇数，插入大堆中
        if (len & 1) 
        {
            int temp = num;
            //如果插入的数比右边的最小值还大，则插入小堆，再将小堆堆顶的元素插入到大堆
            if (minheap.size() > 0 && num > minheap.top()) 
            {
                minheap.push(num);
                temp = minheap.top();
                minheap.pop();
            }
            maxheap.push(temp);
        } 
        // 长度为偶数，插入大堆中
        else 
        {
            int temp = num;
             //如果插入的数比左边的最大值还小，则插入大堆，再将大堆堆顶的元素插入到小堆
            if (maxheap.size() > 0 && num < maxheap.top())
            {
                maxheap.push(num);
                temp = maxheap.top();
                maxheap.pop();
            }
            minheap.push(temp);
        }
    }

    double findMedian() 
    {
        size_t len = minheap.size() + maxheap.size();
        if (len == 0)
        {
             return 0;
        }
           
        // 如果长度是奇数，返回小堆顶元素
        if (len & 1) 
        {
            return minheap.top();
        }

        // 如果长度是偶数，返回两个堆顶元素的平均值
        return (double)(maxheap.top() + minheap.top()) /2; 
    }
};