class Solution {
public:
    string makeFancyString(string s) {
        string ans = "";
        char prev = '!';
        int cnt = 1;
        for(char c : s){
            if(c == prev){
                if(cnt == 2){
                    continue;
                }
                ++cnt;
            }
            else {cnt = 1;}
            ans.push_back(c);
            prev = c;
        }
        return ans;
    }
};
