typedef long long ll;
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& A, int t) {
     int n = A.size(); sort(A.begin(), A.end());
     set<vector<ll>> res; vector<vector<int>> ans;
     unordered_set<ll> st;
     for(int i = 0; i<n; ++i){
        for(int j = i+1; j<n; ++j){
            for(int k = j+1; k<n; ++k){
            ll rem = A[i]+A[j]; rem += (ll)A[k];
            ll target = t;
            target-=rem;
            if(st.count(target))
                res.insert({A[i],A[j],A[k],target});
            }
        }
        st.insert(A[i]);
    }
    for(auto it : res){
        vector<int> tmp;
        for(auto i : it){
            tmp.push_back(i);
        }
        ans.push_back(tmp);
    }
    return ans;
    }
};
