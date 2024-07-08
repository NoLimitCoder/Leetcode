auto init = [](){ ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); return 'c'; }();
class Solution {
public:
    int longestOnes(vector<int>& A, int k) {
        int n = A.size(), mx = 0, i = 0, j = 0, cur_k = 0;
        while(j < n){
            if(A[j] == 1){ j++; }
            else{
                if(cur_k < k) {cur_k++; j++;}
                else { while(A[i] != 0 && i<j) ++i; {cur_k--;} ++i; }
            }
            mx = max(mx,(j-i));
        }
        return mx;
    }
};
