class Solution {
public:
    char kthCharacter(int k) {
        string s = "a";
        while(s.size() < k){
            string tmp = "";
            for(char c : s){
                char t = (c-'a' + 1) + 'a';
                tmp += t;
            }
            s += tmp;
        }
        return s[k-1];
    }
};
