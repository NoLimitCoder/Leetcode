class Solution {
public:
    string stringHash(string s, int k) {
        int i = 0, n = s.size();
        string ans = "";
        while(i<n){
            int sum = 0;
            for(int j = 0; j<k; ++j){
                sum += s[i+j]-'a';
            }
            sum %= 26;
            //cout << sum << '\n';
            ans += string(1,'a'+sum);
            i+=k;
        }
        return ans;
    }
};
