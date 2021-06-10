// Other Possible Solution: sorted list?

// Solution #1: c++ map & map::upper_bound
// O(N*log(N)) where N = number of book... maybe?
class MyCalendar {
public:
    map<int, int> calendar;
    
    bool book(int start, int end) {
        if (this->calendar.size() == 0) {
            this->calendar[start] = end;
            return true;
        }
        auto it_right = this->calendar.lower_bound(start);
        auto it_left = prev(it_right);
        if ((it_right != this->calendar.end() && (*it_right).first < end)
            || (it_right != this->calendar.begin() && ((*it_left).second > start)))
            return false;   
        
        this->calendar[start] = end;
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
