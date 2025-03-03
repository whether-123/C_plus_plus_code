class MovingAverage {
public:
    /** Initialize your data structure here. */

    MovingAverage(int size) : _size(size + 1), sum(0), front(0), rear(0) {
        v.resize(size + 1, 0);
    }

    double next(int val) {

        // 队列满了 队头元素出队
        if ((rear + 1) % _size == front) {
            sum -= v[front];
            v[front] = 0;
            front = (front + 1) % _size;
        }

        sum+=val;
        v[rear] = val;
        rear = (rear + 1) % _size;

        return sum / ((rear - front + _size) % _size);
    }

private:
    //用数组模拟循环队列
    int front;
    int rear;
    int _size;
    double sum;
    vector<int> v;
};