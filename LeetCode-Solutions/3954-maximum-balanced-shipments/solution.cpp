typedef long long ll;
class Solution {
public:
    int maxBalancedShipments(vector<int>& w) {
        int n = w.size(), cnt = 0, j = 1;
        ll tmp = w[0];
        while(j<n){
            if(w[j] < tmp){
                ++cnt;
                if(j+1 < n){ tmp = w[j+1]; j+=2; }
                else break;
            }
            else{tmp = max(tmp,(ll)w[j]); ++j;}
        }
        return cnt;
    }
};
