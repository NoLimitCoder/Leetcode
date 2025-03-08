class Solution {
public:
    int minimumRecolors(string s, int k) {
        int b = 0, w = 0, j = 0;
        for(; j<k; ++j) { if(s[j] == 'B') b++; else w++; }
        int ans = k-b;
        for(; j < s.size(); ++j){
            if(s[j-k] == 'B') b--; else w--;
            if(s[j]   == 'B') b++; else w++;
            ans = min(ans,k-b);
        }
        return ans;
    }
};
