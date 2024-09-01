#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 

struct ost_multiset {
    typedef pair<int, unsigned> pii;
    typedef tree< pii, null_type, less<pii>, rb_tree_tag, tree_order_statistics_node_update > ost;
    ost s;
    unsigned cnt = 0;
    ost_multiset() = default;
    ost_multiset(initializer_list<int> l) {for (int x : l) insert(x); }
    void insert(int x) { s.insert({x, cnt++}); }
    int find_by_order(int k) { return k >= s.size()? -1 : s.find_by_order(k)->first; }
    void erase(int x) { auto it = s.lower_bound({x, 0}); while (it != s.end() && it->first == x) erase(it++); }
    void erase(ost::iterator it) {s.erase(it);}
    size_t size() const { return s.size(); }
};

class Solution {
public:
    vector<int> resultsArray(vector<vector<int>>& q, int k) {
        vector<int> ans;
        int n = q.size();
        ost_multiset st;
        for(int i = 0; i<n; ++i){
            st.insert( abs(q[i][0]) + abs(q[i][1]) );
            ans.push_back( st.find_by_order(k-1));
        }
        return ans;
    }
};
