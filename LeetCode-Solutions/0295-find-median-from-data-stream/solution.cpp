class MedianFinder {
public:
    multiset<double>ms;
    MedianFinder() {
        ms.clear();
    }
    
    void addNum(int num) {
        ms.insert(num*1.0);
    }
    
    double findMedian() {
        int n = ms.size();
        if(n&1){
            int i = 0;
            for (auto it = ms.begin(); it != ms.end(); it++) {
                //cout << *it << ' ';
                if(i == n/2)return *it;
                i++;
            }
        }
        else{
            int i = 0; double ans = 0;
               for (auto it = ms.begin(); it != ms.end(); it++) {
                //cout << *it << ' ';
                if(i == (n/2) -1){
                ans+= *it;
                it++;
                //cout << *it << ' ';
                return (ans + *it)/2.0;
                }
                i++;
            }
        }
        return 0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
