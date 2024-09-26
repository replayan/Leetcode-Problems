class MyCalendar {
    map<int, int> all;

public:
    MyCalendar() {}

    bool book(int start, int end) {
        --end;
        auto t = all.upper_bound(start);
        if (t != all.begin()) {
            auto t1 = t;
            --t1;
            if (t1->second >= start) {
                return false;
            }
        }
        if (t != all.end() && t->first <= end) {
            return false;
        }
        all[start] = end;
        return true;
    }
};