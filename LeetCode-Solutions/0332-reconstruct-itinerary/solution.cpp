auto init = [](){ ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); return 'c'; }();
#define deb(x) cout << #x << ": " << x << '\n'
#define debl(x) cout << #x << ": " << x << ' '
#define rep(i,n) for(int i = 0; i<n; ++i)
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef multiset<int> msi;
class Solution {
public:
//postorder

void dfs(int u, vector<msi> &AL, vector<string>&ans, unordered_map<int,string> &mp2){
    while(!AL[u].size() == 0){
        int v = *AL[u].begin();
        AL[u].erase(AL[u].begin());
        dfs(v,AL,ans,mp2);
    }
    ans.push_back(mp2[u]);
}


    vector<string> findItinerary(vector<vector<string>>& T) {
        //idea map tickets by their lexicographical order to numbers
        //sort elements in adj list, run dfs, when you take an edge you pop it from the set base case will be handled because set will become empty   
        set<string> st;
        rep(i,T.size()){st.insert(T[i][0]); st.insert(T[i][1]);}
        unordered_map<string,int> mp;
        unordered_map<int,string> mp2;
        int n = st.size(), i = 0;
        for(auto s : st){ mp[s] = i; mp2[i] = s; ++i;}
        vector<msi> AL(n);
        rep(i,T.size()){
            int u = mp[T[i][0]], v = mp[T[i][1]];
            AL[u].insert(v);
        }
        vector<string> ans;
        dfs(mp["JFK"],AL,ans,mp2);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
