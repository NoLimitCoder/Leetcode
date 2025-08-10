class Solution {
public:
    bool reorderedPowerOf2(int n) {
        string s = to_string(n);
        sort(s.begin(), s.end());
        do{
            if(s[0] == '0') continue;
            n = stoi(s);
            if(__builtin_popcount(n) == 1) return 1;
        } while(next_permutation(s.begin(),s.end()));
        return 0;
    }
};
