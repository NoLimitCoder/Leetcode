#define deb(x) cout << #x << ": "<< x << '\n'
#define debl(x) cout << #x << ": "<< x << ' '

class Solution {
public:
    int longestSubarray(vector<int>& A, int k) {
        int n = A.size();
        multiset<int>st;
        int i = 0, j = 0;
        int ans = 1;
        while(j<n){
            //debl(i); deb(j);
            if(st.empty()){st.insert(A[j++]); continue;}
            //insert in the window
            if( abs(*st.begin() - A[j]) <= k && abs(*st.rbegin() - A[j]) <= k){
                st.insert(A[j++]);
            }
            //removing from the window
            else{
                st.erase(st.find(A[i++]));
            }
            ans = max(ans, (int) st.size());
        }
        return ans;
    }
};
