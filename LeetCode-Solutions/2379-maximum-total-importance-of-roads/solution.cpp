class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
     vector<int> mp(n); long long ans = 0;
     for(int i = 0; i<roads.size(); ++i)
        {mp[roads[i][0]]++; mp[roads[i][1]]++;}
     sort(mp.begin(), mp.end());
     for(int i = 0; i<mp.size(); ++i){
        ans += mp[i]*1LL*(i+1);
     }
     return ans;
    }
};
