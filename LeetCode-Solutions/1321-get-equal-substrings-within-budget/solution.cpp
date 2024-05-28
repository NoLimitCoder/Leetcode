#pragma GCC optimize("O3,unroll-loops")
class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        //sliding window
        int i = 0, j = 0, curCost = 0, maxWindow = 0, n = s.size();
        while(j < n){
            curCost += abs(s[j] - t[j]);
            while(curCost > maxCost){
                curCost -= abs(s[i] - t[i++]);
            }
            maxWindow = max(maxWindow, (++j)-i);
        }
        return maxWindow;
    }
};
