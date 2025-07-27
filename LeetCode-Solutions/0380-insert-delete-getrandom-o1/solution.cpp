class RandomizedSet {
public:
    vector<int> v;
    unordered_map<int,int> mp;
    RandomizedSet() {
        v.clear(); mp.clear();
    }
    bool insert(int val) {
        if(mp.find(val) != mp.end()) return 0;
        v.push_back(val); mp[val] = v.size()-1;
        return 1;
    }
    
    bool remove(int val) {
        if(mp.find(val) == mp.end()) return 0;
        int idx_val = mp[val], idx_last = v.size()-1, last = v.back();
        v[idx_val] = last;  mp[last] = idx_val;
        v.pop_back(); mp.erase(mp.find(val));
        return 1;
    }
    
    int getRandom() {
        return v[rand()%v.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
