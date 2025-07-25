class Solution {
public:
    int maxSum(vector<int>& A) {
        int res = 0; set<int> st;
        for(int i : A) if(i >= 0 && !st.count(i)) {res += i; st.insert(i);}
        if(st.size()) return res;
        else{
            return *max_element(A.begin(), A.end());
        }
    }
};
