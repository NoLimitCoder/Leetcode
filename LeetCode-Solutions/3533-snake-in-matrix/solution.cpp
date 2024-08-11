class Solution {
public:
    int finalPositionOfSnake(int n, vector<string>& c) {
        vector<vector<int>> grid(n,vector<int>(n));
        int idx = 0;
        for(int i = 0; i<n; ++i){
            for(int j = 0; j<n; ++j){
                grid[i][j] = idx++;
                cout << grid[i][j] << ' ';
            }cout << '\n';
        }
        int i = 0, j = 0;
        for(string s : c){
            if(s == "UP")    --i;
            if(s == "DOWN")  ++i;
            if(s == "RIGHT") ++j;
            if(s == "LEFT")  --j;
        }
        return grid[i][j];
    }
};
