class Solution {
public:
    vector<string> validStrings(int n) {
        vector<string> ans;
        for(int i = 0; i<1<<n; ++i){
            string tmp = "";
            //cout << "i: ";
            for(int j = n-1; j >=0; --j){
                 bool bit = i&(1<<j);
                 //cout << bit << ' ';
                tmp += to_string(bit);
            } //cout << '\n';
            ans.push_back(tmp);
        }
        vector<string> ans2;
        for(auto it : ans) {
            bool flag = 1;
            for(int i = 1; i<it.size(); ++i){
                if(it[i] == '0' && it[i-1] == '0'){flag = 0; break;}
            }
            if (flag)ans2.push_back(it);
        }
        return ans2;
    }
};
