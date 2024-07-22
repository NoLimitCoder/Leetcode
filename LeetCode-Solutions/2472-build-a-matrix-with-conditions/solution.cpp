class Solution {
public:
    vector<int> khan(int k,vector<vector<int>>& Conditions){
     vector<int>graph[k+1], degree(k+1), ans; queue<int>q; 
     for(auto i:Conditions){ graph[i[0]].push_back(i[1]); degree[i[1]]++; }
     for(int i=1;i<k;i++){ if(degree[i]==0) q.push(i); }
     while(!q.empty()){
         int t=q.front(); q.pop(); ans.push_back(t);
         for(auto i:graph[t]) { degree[i]--; if(degree[i]==0) q.push(i); }
     }

    return ans;
    }
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        vector<int>row=khan(k+1,rowConditions); vector<int>col=khan(k+1,colConditions); unordered_map<int ,int>mp;
        if(row.size()<k || col.size()<k){ return {}; } 
        for(int i=0;i<k;i++){ mp[col[i]]=i; }
        vector<vector<int>>ans(k,vector<int>(k,0));
        for(int i=0;i<k;i++){ int col_pos=mp[row[i]]; ans[i][col_pos]=row[i]; }
        return ans;
    }
};
