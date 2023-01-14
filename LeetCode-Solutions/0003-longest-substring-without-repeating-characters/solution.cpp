class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        //Sliding window
        map<char,int> mp;
        int longest = 0, cur = 0, i = 0, j = 0, k = 0, n = s.size();
        while(i<n){
            if(mp.find(s[i]) == mp.end()){
                mp[s[i]] = i; cur++;
            }
            else{
                cout << k << '\n';
                j = max(k, mp[s[i]] + 1);
                cur = (i - j) +1;
                k = max(k, mp[s[i]]+1);
                mp[s[i]] = i;
            }
            longest = max(longest,cur);
            ++i;
        }
        return longest;
    }
};
