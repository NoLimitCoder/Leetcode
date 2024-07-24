auto init = []() { ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); return 'c'; }();
class Solution {
public:
    vector<int> sortJumbled(vector<int>& mp, vector<int>& A) {
        sort(A.begin(), A.end(), [&mp](int a, int b){
            int a2 = 0, i = 0; if(a == 0) a2 = mp[0];
            while(a){ a2 += mp[(a%10)] * pow(10,i); a/=10; ++i; }
            int b2 = 0; i = 0; if(b == 0) b2 = mp[0];
            while(b){ b2 += mp[(b%10)] * pow(10,i); b/=10; ++i; }
            return a2<b2;
        });
        return A;
    }
};
