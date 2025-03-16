class MyCalendar {
public:
    // 维护一个日程安排
    // 且schedule中的日程，不会互相产生重复订阅
    map<int, int> schedule;
    MyCalendar() {}

    bool book(int start, int end) {
        auto it = schedule.lower_bound(start);

        // 与后一个时间产生重复预订
        // 防止不存在后一个日程 导致越界
        if (it != schedule.end() && it->first < end) {
            return false;
        }

        // 与前一个时间产生重复预订
        // 防止不存在前一个日程 导致越界
        if (it != schedule.begin() && (--it)->second > start) {
            return false;
        }
        // 走到这里 不会产生重复预订
        schedule[start] = end;
        return true;
    }
};