class Solution {
public:


void helper(int r, int c, vector<vector<char>>& board, bool &ans){
    set<int>st = {};
    for(int i = 0; i<3; ++i){
        for(int j = 0; j<3; ++j){
            if(board[r+i][c+j] == '.')continue;
                if(st.find(board[r+i][c+j]) != st.end())
                    {ans = false;}
                st.insert(board[r+i][c+j]);
               // cout << board[r+i][c+j] << ' ';
            }
    }
    //cout << '\n';
}
    bool isValidSudoku(vector<vector<char>>& board) {
        bool ans = true;
        //Case 1: Each row must contain the digits 1-9 without repetition.
        for(int i = 0; i< board.size(); ++i){
            set<int>st = {};
            for(int j = 0; j< board[0].size(); ++j){
                if(board[i][j] == '.')continue;
                if(st.find(board[i][j]) != st.end()){
                    ans = false;
                }
                st.insert(board[i][j]);
                //cout << board[i][j] << ' ';
            }//cout << '\n';
        }
        //cout << '\n';
    //Case2: Each column must contain the digits 1-9 without repetition.
            for(int i = 0; i< board.size(); ++i){
            set<int>st = {};
            for(int j = 0; j< board[0].size(); ++j){
                if(board[j][i] == '.')continue;
                if(st.find(board[j][i]) != st.end()){
                    ans = false;
                }
                st.insert(board[j][i]);
                //cout << board[j][i] << ' ';
            }//cout << '\n';
        }
        //cout << '\n';
    //Case 3 Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9 without repetition.
    for(int i = 0; i<3; ++i){
        for(int j = 0; j<3; ++j){
            helper(i*3,j*3,board,ans);
        }
    }
    return ans;















    return ans;
    }
};
