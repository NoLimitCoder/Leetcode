class Solution {
public:
    int longestPalindrome(vector<string>& words) {
     deque<string>dq;
     unordered_map<string,int>mp;
     int ans = 0;
     for(string c : words){
        string s = ""; s+= c[1]; s+=c[0];
        if(mp[s] > 0){
            mp[s]--;
            ans += 4;
        }
        else{
            mp[c]++;
        }
     }
    for(auto it : mp){
        if(it.second == 1 && it.first[0] == it.first[1]){ans+=2; break;}
    }
    return ans;
    }
};
