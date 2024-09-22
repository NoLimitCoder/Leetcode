typedef long long ll;
class Solution {
public:
    struct worker{
        ll val, m, c;
        bool operator<(const worker &other) const{
        return val > other.val;
  }
    };
    long long minNumberOfSeconds(int x, vector<int>& A) {
        priority_queue<worker>pq;
        worker cur;
        for(int i : A) pq.push( {i, 2, i} );
        ll cnt = 0;
        while(x){
            cur = pq.top(); pq.pop(); --x;
            pq.push({cur.val + cur.c*cur.m, cur.m+1, cur.c});
        }
        return cur.val;
    }
};
//[2,2,3,100]
