auto init = []() { ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); return 'c'; }();
class Solution {
public:

struct robot{
    int p, h, i; char d;
    bool operator < (const robot &other) const{ return p < other.p; }
};
    vector<int> survivedRobotsHealths(vector<int>& P, vector<int>& H, string D) {
        int n = P.size(); vector<robot> R(n); stack<robot> stk;
        for(int i = 0; i<n; ++i){ R[i] = {P[i], H[i], i, D[i]}; }
        sort(R.begin(), R.end());
        for(int i = 0; i<n; ++i){
            if(stk.empty()) { stk.push(R[i]); continue; }
            bool flag = 1;
            while(!stk.empty() && (R[i].d == 'L' && stk.top().d == 'R')) {
                if(R[i].h > stk.top().h) //if the current one is bigger than top, pop top, decrease this one by one, and flag a push
                    { stk.pop(); R[i].h--; flag = 1; } 
                else if(R[i].h < stk.top().h) //if the current one is lesser than top, decrease top by one, unflag the push, and go to next iteration
                    { stk.top().h--; flag = 0; break; }
                else //they're both equal pop top, unflag the push, and go to next iteration
                    { stk.pop(); flag = 0; break; }
            }
            if(flag) stk.push(R[i]);
        }
        vector<robot> tmp; vector<int> ans;
        while(!stk.empty()) { tmp.push_back(stk.top()); stk.pop(); }
        sort(tmp.begin(), tmp.end(), [](robot &a, robot &b){ return a.i < b.i; });
        for(auto it : tmp) ans.push_back(it.h);
        return ans;
    }
};
