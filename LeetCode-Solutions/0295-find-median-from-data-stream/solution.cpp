#include <queue>
using namespace std;

class MedianFinder {
    // max‐heap for the smaller half
    priority_queue<int> lo;
    // min‐heap for the larger half
    priority_queue<int, vector<int>, greater<int>> hi;
public:
    MedianFinder() {
        // nothing to do
    }
    
    void addNum(int num) {
        // 1) Always push into lo first
        lo.push(num);
        // 2) Balance: move the largest of lo into hi
        hi.push(lo.top());
        lo.pop();
        
        // 3) Maintain size property: lo can have at most one more than hi
        if (hi.size() > lo.size()) {
            lo.push(hi.top());
            hi.pop();
        }
    }
    
    double findMedian() {
        // If odd total, lo has one extra
        if (lo.size() > hi.size())
            return lo.top();
        // even total → average of tops
        return (lo.top() + hi.top()) * 0.5;
    }
};

