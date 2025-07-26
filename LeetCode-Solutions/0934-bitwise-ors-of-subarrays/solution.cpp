class Solution {
public:
    int subarrayBitwiseORs(vector<int>& A) {
        unordered_set<int> res, prev;
        for (int a : A) {
            unordered_set<int> cur = {a};
            for (int x : prev)
                cur.insert(x | a);
            prev = cur;
            res.insert(cur.begin(), cur.end());
        }
        return res.size();
    }
};

