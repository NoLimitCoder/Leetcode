class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& A, int k) {
        int n = A.size(); multiset<int> st; vector<int> ans;
        //setup the window
        for(int i = 0; i<k; ++i){st.insert(A[i]);}
        //add first element to window
        ans.push_back(*st.rbegin());
        for(int i = k; i<n; ++i){
            st.erase(st.find(A[i-k]));
            st.insert(A[i]);
            ans.push_back(*st.rbegin());
        }
        return ans;
    }
};
