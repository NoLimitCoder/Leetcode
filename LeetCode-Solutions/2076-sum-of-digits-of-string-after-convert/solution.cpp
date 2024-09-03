class Solution {
public:
    int getLucky(string s, int k) {
        string tmp = "";
        for(int i = 0; i<s.size(); ++i) tmp += to_string(s[i] - 'a' + 1);
        s = tmp;
        while(k--){
            tmp = "";
            for(int i = 0; i<s.size(); ++i) tmp += to_string(s[i] - '0');
            int sum = 0;
            for(char c : tmp) sum += c-'0';
            s = to_string(sum);
        }
        return stoi(s);
    }
};
