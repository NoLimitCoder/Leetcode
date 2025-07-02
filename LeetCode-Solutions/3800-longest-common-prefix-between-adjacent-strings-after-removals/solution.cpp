class Solution {
public:
    vector<int> longestCommonPrefix(vector<string>& words) {
        int n = words.size(); if (n == 1) return {0};
        vector<int> left(n-1), right(n-1);
        for (int i = 0; i < n-1; ++i) {
            int len = 0; while (len < words[i].size() && len < words[i+1].size() 
            && words[i][len] == words[i+1][len]) len++; left[i] = right[i] = len;
        }
        vector<int> prefix_max(n-1), suffix_max(n-1); prefix_max[0] = left[0];
        for (int i = 1; i < n-1; ++i) prefix_max[i] = max(prefix_max[i-1], left[i]); suffix_max[n-2] = right[n-2];
        for (int i = n-3; i >= 0; --i) suffix_max[i] = max(suffix_max[i+1], right[i]);
        vector<int> answer(n, 0);
        for (int i = 0; i < n; ++i) {
            int current_max = 0;
            if (i > 0 && i < n-1) {
                int len = 0; while (len < words[i-1].size() && len < words[i+1].size() 
                && words[i-1][len] == words[i+1][len]) len++;
                current_max = len;
            }
            if (i-2 >= 0)   current_max = max(current_max, prefix_max[i-2]);
            if (i+1 <= n-2) current_max = max(current_max, suffix_max[i+1]);
            answer[i] = current_max;
        }
        return answer;
    }
};
