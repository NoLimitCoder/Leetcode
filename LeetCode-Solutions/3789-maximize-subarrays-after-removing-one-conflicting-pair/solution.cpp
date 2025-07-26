class Solution {
public:
    long long maxSubarrays(int n, vector<vector<int>>& conflictingPairs) {
        vector<vector<int>> lefts(n+1);
        for (auto& pair : conflictingPairs) {
            int l = pair[0], r = pair[1];
            if (l > r) swap(l, r);
            lefts[r].push_back(l);
        }
        long long ans = 0;
        vector<long long> gains(n+1);
        pair<int, int> max_lefts = {0, 0};
        for (int r = 1; r <= n; r++) {
            for (int l : lefts[r]) {
                if (l > max_lefts.first) {
                    max_lefts.second = max_lefts.first;
                    max_lefts.first = l;
                } else if (l > max_lefts.second) {
                    max_lefts.second = l;
                }
            }
            ans += r - max_lefts.first;
            gains[max_lefts.first] += max_lefts.first - max_lefts.second;
        }

        return ans + *max_element(gains.begin(), gains.end());
    }
};
