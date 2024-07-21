class Solution {
public:
    bool doesAliceWin(string s) {
        int n = s.size();
        vector<int> P(n);
        int sum = 0;
        for(int i = 0; i<n; ++i){
            char c = s[i];
            if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') 
                ++sum;
            //if(i > 0) P[i]+= P[i-1];
        }
        if(sum == 0) return false;
        return true;

    }
};
