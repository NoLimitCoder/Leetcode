#define ios() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

class Solution {
public:
    void dfs(string cur, int opened, int closed,vector<string>&ans,int &n){
        if(closed > opened || opened > n || closed > n) return;
        if(opened == n && closed == n){ans.push_back(cur);}
        dfs(cur+"(",opened+1,closed,ans,n);
        dfs(cur+")",opened,closed+1,ans,n);
    }



    vector<string> generateParenthesis(int &n) {
        ios();
        vector<string> ans;
        dfs("",0,0,ans,n);
        return ans;
    }
};
