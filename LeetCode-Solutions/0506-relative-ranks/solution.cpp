class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<int> tmp = score;
        int n = score.size();
        sort(tmp.rbegin(),tmp.rend());
        map<int,string> mp;
        for(int i = 0; i<n; ++i){
            if(i == 0) mp[tmp[i]] = "Gold Medal";
            else if(i == 1) mp[tmp[i]] = "Silver Medal";
            else if(i == 2) mp[tmp[i]] = "Bronze Medal";
            else mp[tmp[i]] = to_string(i+1);
        }
        vector<string> ans;
        for(int i = 0; i<n; ++i){
            ans.push_back(mp[score[i]]);
        }
        return ans;
    }
};
