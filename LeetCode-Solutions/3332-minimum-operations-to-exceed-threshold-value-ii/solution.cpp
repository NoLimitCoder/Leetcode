typedef long long ll;
class Solution {
public:
    int minOperations(vector<int>& A, int k) {
        priority_queue <ll, vector<ll>, greater<ll>> pq;
        for(int i : A) pq.push(i*1LL);
        int ans = 0;
        while(!pq.empty()){
            //cout << pq.top() << '\n';
            if(pq.top() < k){
                ll x = pq.top(); pq.pop();
                ll y = pq.top(); pq.pop();
                pq.push(min(x, y) * 2 + max(x, y));
                ans++;
            }
            else{
                break;
            }
        }
        return ans;
    }
};
