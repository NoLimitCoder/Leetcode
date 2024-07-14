auto init = []() { ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); return 'c'; }();
class Solution {
public:
    string countOfAtoms(string s) {
        map<string, int> atoms; stack<int> multipliers;
        string ans; int digit = 1, multiplier = 1, n = s.size();
        for (int i = n-1; i >= 0; --i) {
            if (isalpha(s[i]) && islower(s[i])){ 
                int len = 0; while (i >= 0 && islower(s[i])) {--i; ++len;}
                string atom = s.substr(i,len+1);
                atoms[atom] += digit * multiplier; digit = 1;
            } else if (isalpha(s[i]) && isupper(s[i])) {
                string atom = string(1, s[i]);
                atoms[atom] += digit * multiplier; digit = 1;
            } else if (isdigit(s[i])) {
                digit = s[i] - '0'; int pw = 10;
                while (i-1 >= 0 && isdigit(s[i - 1])) 
                    { digit += pw * (s[--i]-'0'); pw *= 10; }
            } else if (s[i] == ')') {
                multipliers.push(multiplier); multiplier *= digit; digit = 1;
            } else {
                multiplier = multipliers.top(); multipliers.pop();
            }
        }
        for (auto [atom, count] : atoms) 
            { ans += atom; if (count > 1) {ans += to_string(count);} }
        return ans;
    }
};
