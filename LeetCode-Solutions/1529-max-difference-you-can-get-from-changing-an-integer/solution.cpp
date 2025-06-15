class Solution {
public:
    int maxDiff(int num) {
        string st1 = to_string(num), st2 = to_string(num);
        char ch1 = '\0', ch2 = '\0';
        for (char c : st1) if (c != '9') { ch1 = c; break; }
        if (ch1) for (char &c : st1) { if (c == ch1) c = '9'; }
        int num1 = stoi(st1), idx2 = -1;
        for (int i = 0; i < st2.size(); i++)
            if (st2[i] != '1' && st2[i] != '0') { ch2 = st2[i]; idx2 = i; break; }
        if (ch2) for (char &c : st2) if (c == ch2) { c = (idx2 == 0) ? '1' : '0'; }
        int num2 = stoi(st2);
        return num1 - num2;
    }
};

