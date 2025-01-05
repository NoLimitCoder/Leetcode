auto init = []() { ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); return 0; }();
class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& V) {
        int n = s.size(); vector<int> diff(n+1,0);
        for(auto vec : V){
            int offset = (vec[2] == 0? -1 : 1), start = vec[0], end = vec[1];
            diff[start] += offset; diff[end+1] -= offset;
        }
        for(int i = 0; i<n; ++i){
            if(i) diff[i] += diff[i-1];
            s[i] = ((s[i] - 'a' + (diff[i]%26 +26))%26) + 'a';
        }
        return s;
    }
};
