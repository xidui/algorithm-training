// 148ms
// multiset solution
class MedianFinder {
public:
    multiset<int> si;
    multiset<int>::iterator it;

    // Adds a number into the data structure.
    void addNum(int num) {
        si.insert(num);
        if (si.size() == 1) {
            it = si.begin();
            return;
        }
        if (num < *it && si.size() % 2 == 0) --it;
        if (num >= *it && si.size() % 2 == 1) ++it;
    }

    // Returns the median of current data stream
    double findMedian() {
        if (si.size() == 0) return 0;
        if (si.size() % 2 == 1) return *it;
        return (*(++it) + *(--it) + 0.0) / 2;
    }
};