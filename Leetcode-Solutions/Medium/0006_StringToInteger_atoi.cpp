class Solution {
public:
    int myAtoi(string s) {
        unsigned int cursor = 0;
        bool isPositive = true;
        while (s[cursor] == ' ') {
            cursor++;
        }

        if (s[cursor] == '+') cursor++;
        else if (s[cursor] == '-') {
            isPositive = false;
            cursor++;
        }
        
        unsigned long cur = 0;
        unsigned long next = 0;
        unsigned long ovfThreshold = (isPositive) ? (1lu << 31) - 1 : 1lu << 31;
        while (isdigit(s[cursor])) {
            next = cur * 10 + (s[cursor] - 48);
            if (next > ovfThreshold) {
                cur = ovfThreshold;
                break;
            }
            cur = next;
            cursor++;            
        }
        
        return (int)((isPositive) ? cur : -cur);
    }
};
