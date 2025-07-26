class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& A, int k) {
        multiset<int> st; int n = A.size();
        for(int i = 0; i<k; ++i) st.insert(A[i]);
        int mx = *st.rbegin(), l = 0;
        vector<int> ans; ans.push_back(mx);
        for(int r = k; r<n; ++r){
            st.insert(A[r]);
            st.erase(st.find(A[l++]));
            ans.push_back(*st.rbegin());
        }
        return ans;
    }
};
