class Solution {
public:
    void solve(int col, vector<string> &board, vector<vector<string>> &ans, 
               vector<int> &left, vector<int> &udia, vector<int>& ldia, int n) {
        if(col == n) {
            ans.push_back(board);
            return;
        }
        for(int row = 0; row < n; row++) {
            if(left[row] == 0 && udia[row + col] == 0 && ldia[col - row + n - 1] == 0) {
                board[row][col] = 'Q';
                left[row] = 1;
                ldia[col - row + n - 1] = 1;
                udia[row + col] = 1;

                solve(col + 1, board, ans, left, udia, ldia, n);

                board[row][col] = '.';
                left[row] = 0;
                ldia[col - row + n - 1] = 0;
                udia[row + col] = 0;
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n, string(n, '.'));
        vector<int> left(n, 0), udia(2 * n, 0), ldia(2 * n, 0);
        solve(0, board, ans, left, udia, ldia, n);
        return ans;
    }
};
