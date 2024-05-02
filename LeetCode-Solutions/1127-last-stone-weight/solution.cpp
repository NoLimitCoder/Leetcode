class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for(int stone : stones){
            pq.push(stone);
        }
        while(pq.size() != 1){
            int y, x;
            y = pq.top(); pq.pop();
            x = pq.top(); pq.pop();
            pq.push(y-x);
        }
        return pq.top();
    }
};
