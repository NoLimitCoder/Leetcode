#pragma GCC optimize("O3,unroll-loops")
class Solution {
public:

    bool compare(vector<int> &a, vector<int> &b){
        for(int i = 0; i<26; ++i)
            {if(a[i] != b[i] && a[i] != -1) return false;}
        return true;
    }

    bool checkInclusion(string s1, string s2) {
        if(s1.size() > s2.size()) return false;
        vector<int> a(26,-1), b(26,-1);
        int s = 0, n = s1.size();
        for(int i = 0; i<n; ++i){
            if(a[s1[i] - 'a'] == -1) {a[s1[i] - 'a'] = 0;}
            a[s1[i] - 'a']++;
            if(b[s2[i] - 'a'] == -1) {b[s2[i] - 'a'] = 0;}
            b[s2[i] - 'a']++;
        }
        if(compare(a,b)) return true;
        while(n < s2.size()){
            if(b[s2[n] - 'a'] == -1) {b[s2[n] - 'a'] = 0;}
            b[s2[s] - 'a']--;
            b[s2[n] - 'a']++;
            if(compare(a,b)) return true;
            ++s; ++n;
        }
        return false;
    }
};
