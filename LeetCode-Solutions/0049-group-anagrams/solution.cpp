#include <bits/stdc++.h>

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
       map<string,vector<int>>mp;
        for(int i = 0; i< strs.size(); ++i){
            string t = strs[i];
            sort(t.begin(),t.end());
            mp[t].push_back(i);
        }
        vector<vector<string>> ans;
        for(auto it: mp){
            vector<string> word;
            for(int idx : it.second){
                word.push_back(strs[idx]);
            }
            ans.push_back(word);
        }
        return ans;
    }
};
