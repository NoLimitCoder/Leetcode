#define deb(x) cout << #x << ": " << x << '\n';

class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        map<int,int>freq;
        map<int,int> idx;
        set<int>ans;
        int n = cards.size();
        for(int i = 0; i<n;++i){
            freq[cards[i]]++;
            if(freq[cards[i]] > 1)
                {ans.insert(i - idx[cards[i]] +1);}
            idx[cards[i]] = i;
        }
        if(ans.size() == 0)return -1;
        else return *ans.begin();
    }
};
