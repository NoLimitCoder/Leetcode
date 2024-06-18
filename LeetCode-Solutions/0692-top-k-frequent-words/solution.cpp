class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> mp;
        for(string w : words)mp[w]++;
        auto cmp = [&mp](string a, string b){ return mp[a] > mp[b] || mp[a] == mp[b] && a < b;};
        priority_queue<string,vector<string>,decltype(cmp)> pq(cmp);
        for(auto it : mp){
            pq.push(it.first);
            while(pq.size() > k) pq.pop();
        }
        vector<string> ans;
        while(k--) {ans.push_back(pq.top()); pq.pop();}
        sort(ans.begin(), ans.end(), cmp);
        return ans;
    }
};
