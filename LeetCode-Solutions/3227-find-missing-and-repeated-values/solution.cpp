class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& G) {
     map<int,int>mp;
     int n = G.size();
     for(int i = 1; i<=n*n; ++i){mp[i]++;}
     for(int i = 0; i<G.size(); ++i){
        for(int j = 0; j<G[0].size(); ++j){
            mp[G[i][j]]++;
        }
     }  
     
     int rep = -1, mis = -1;
     for(auto it : mp){
        if(it.second == 3) rep = it.first;
        if(it.second == 1) mis = it.first;
     }
     return {rep,mis};
    }
};
