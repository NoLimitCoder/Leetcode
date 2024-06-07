#pragma GCC optimize("O3,unroll-loops")

class Solution {
public:

vector<string> split(const char *str, char c = ' '){
    vector<string> result;
    do{
        const char *begin = str;
        while(*str != c && *str) str++;
        result.push_back(string(begin, str));
    } while (0 != *str++);
    return result;
}

    string replaceWords(vector<string>& dictionary, string sentence) {
        unordered_set<string> st(dictionary.begin(), dictionary.end());
        vector<string> tokens = split(sentence.c_str(), ' ');
        string ans = "";
        for(int x = 0; x<tokens.size(); ++x){
            string str = tokens[x];
            int n = str.size();
            string tmp = "";
            for (int i = 0; i<n; ++i){
                tmp.push_back(str[i]);
                if(st.find(tmp) != st.end()){tokens[x] = tmp; break;}
            }
            ans +=tokens[x]; ans.push_back(' ');
        }
        ans.pop_back();
        return ans;
    }
};
