class Solution {
public:

bool valid(vector<int> &mp, int k){
    return (mp['a'-'a'] && mp['e'-'a'] && mp['i'-'a'] && mp['o'-'a'] && mp['u'-'a'] && mp[26] == k);
    //return 0;
}
    int countOfSubstrings(string s, int k) {
        int n = s.size();
        int ans = 0;
        for(int i = 0; i< n; ++i){
            for(int len = 1; len <= n-i; ++len){
                vector<int> mp(27,0);
                string tmp = s.substr(i,len);
                for(char c : tmp){
                    if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
                        mp[c-'a']++;
                    else 
                        mp[26]++;
                }
                if(valid(mp,k)) ans ++;
            }
        }
        return ans;
    }
};
