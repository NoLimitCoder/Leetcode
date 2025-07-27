#define rep(i, n) for(int i = 0; i < n; ++i)

class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        map<int, pair<int,int>> mp;
        rep(r, m) rep(c, n) {mp[mat[r][c]] = {r, c};}
        vector<int> r_cnt(m, 0), c_cnt(n, 0);
        rep(i, arr.size()) {
            auto [r, c] = mp[arr[i]];
            r_cnt[r]++; c_cnt[c]++;
            if (r_cnt[r] == n ||  c_cnt[c] == m){return i;}
        }
        return -1;
    }
};

