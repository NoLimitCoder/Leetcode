class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> ans;
        int n = s.size();
        int i = 0;
        for(; i+k<n; i+=k){
            string tmp = "";
            for(int j = 0; j <k; ++j)
                {tmp += s[i+j];}
            ans.push_back(tmp);
        }
        if(i < n){
            string tmp = "";
            for(; i<n; ++i){
                tmp += s[i];
            }
            while(i%k != 0) {tmp += fill; ++i;}
            ans.push_back(tmp);
        }
        return ans;
    }
};
