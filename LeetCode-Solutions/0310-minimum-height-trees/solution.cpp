class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& E) {
        if (n == 1) return {0}; //base case
        //getting input
        vector<vector<int>> AL(n); unordered_map<int,int> mp; queue<int> q;
        for(int i = 0; i<E.size(); ++i){
            int u = E[i][0], v = E[i][1];
            AL[u].push_back(v); mp[u]++;
            AL[v].push_back(u); mp[v]++;
        }
        //compute indegree, push leaves (indegree == 1) to queue
        for(auto it : mp){ if(it.second == 1) q.push(it.first); }
        while(n>2){ //while there's more than 2 elements in this graph (there's a proof somewhere)
            int len = q.size(); n-=len; //go through every leave in the queue
            while(len--){
                int u = q.front(); q.pop();
                for(int v : AL[u]){
                    if(--mp[v] == 1) q.push(v); //decrease the indegree of everyone in the graph that had this leave as a child and if something now became a leave, added it to the queue
                }
            }
        }
        vector<int> ans;
        while(!q.empty()){ans.push_back(q.front()); q.pop();} //at the end the midpoint(s) will have at most 1 edge and they will be in the queue
        return ans;
    }
};
