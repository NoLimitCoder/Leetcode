class Solution {
public:
    string smallestSubsequence(string s) {
        int n = s.size(), k = 0; vector<deque<int>> dq(26);
        for(int i = 0; i < n; ++i) dq[s[i]-'a'].push_back(i);
        for(int i = 0; i < 26; ++i) if(!dq[i].empty()) ++k;
        string ans = "";
        while(ans.size() < k) {
            int mn = n;
            for(int j = 0; j < 26; ++j) if (!dq[j].empty()) mn = min(mn, dq[j].back());

            for(int i = 0; i < 26; ++i) if (dq[i].size()){
                int idx = dq[i].front();
                if(idx <= mn) {
                    ans.push_back(char('a' + i));
                    for(int j = 0; j < 26; ++j) 
                        { while (!dq[j].empty() && dq[j].front() < idx) dq[j].pop_front(); }
                    dq[i].clear();
                    break;
                }
            }
        }
        return ans;
    }
};

