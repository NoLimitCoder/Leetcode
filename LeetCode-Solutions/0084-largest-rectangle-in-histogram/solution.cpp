class Solution {
public:

struct rectangle{int height, idx;};
    int largestRectangleArea(vector<int>& heights) {
        heights.push_back(-1);
        stack<rectangle> stk{};
        int mx{}, n{(int)heights.size()};
        for(int i{}; i < n; ++i){
            int start{i};
            while(!stk.empty() && stk.top().height > heights[i]){
                auto [height, idx]{stk.top()}; stk.pop();
                mx = max(mx, height * (i-idx));
                start = idx;
            }
            stk.push({heights[i], start});
        }
        return mx;
    }
};
