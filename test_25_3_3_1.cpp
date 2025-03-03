class RecentCounter {
public:
    RecentCounter() { }
    
    int ping(int t) {
     q.push_back(t);
     //因为时间是递增的 间隔大于3000出队(后面不会用到)
     while(q.front()<(t-3000))  q.pop_front();
      
      return q.size();
    }
private:
   deque<int> q;
};