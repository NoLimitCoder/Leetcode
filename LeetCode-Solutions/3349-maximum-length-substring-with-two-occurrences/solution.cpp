class Solution {
public:
    string S;
    
    bool check(string test){
        map<char,int> mp;
        bool flag = true;
        for(int i = 0; i<test.size(); ++i){
            mp[test[i]]++;
            if(mp[test[i]] > 2) flag = false;
        }
        return flag;
    }
    
    int maximumLengthSubstring(string s) {
        S = s;
        int mx = 0;
        for (int start = 0; start < s.size(); ++start) {
            for (int end = start; end < s.size(); ++end) {
                string str2 = s.substr(start, end - start + 1);
                if(check(str2)) {mx = (mx > str2.size()) ? mx : str2.size();}
                
            }
        }
            return mx;
    }
};
