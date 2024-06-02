#pragma GCC optimize("O3,unroll-loops")
class Solution {
public:
    int dx[4]={1, -1, 0,  0};
    int dy[4]={0,  0, 1, -1};
    bool flag;
    struct P {int x, y;};

    void dfs(int idx, P pos, vector<vector<char>>& board, string &word){
        if(pos.x < 0 || pos.x >= board.size() || pos.y < 0 || pos.y >= board[0].size() || board[pos.x][pos.y] == '#' 
        || flag || board[pos.x][pos.y] != word[idx]) return;
        //cout << word[idx] << ' ';
        if(idx == word.size()-1) {flag = 1; return;}
        char tmp = board[pos.x][pos.y];
        board[pos.x][pos.y] = '#';
        for(int k = 0; k<4; ++k){
            dfs(idx+1,{pos.x+dx[k], pos.y+dy[k]}, board, word);
        }
        board[pos.x][pos.y] = tmp;
    }


    bool exist(vector<vector<char>>& board, string word) {
        flag = 0;
        string cur = "";
        int m = board.size();
        int n = board[0].size();
        //string rv = "";
        for(int i = 0; i<m; ++i)
            for(int j = 0; j<n; ++j)
            dfs(0,{i,j},board,word);
        return flag;
    }
};
