class Solution {
public:
    string getEncryptedString(string s, int k) {
        string s2 = s;
        int n = s.size();
        for(int i = 0; i<n; ++i){
            //cout << i << ' ';
            int kth = (i+k)%n;
            cout << kth << ' ';
            s[i] = s2[ kth ];
        }
        return s;
    }
};
