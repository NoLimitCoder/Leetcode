#pragma GCC optimize("O3,unroll-loops")
class Solution {
public:
    
    bool cmp(unordered_map<char,int> &mps, unordered_map<char,int> &mpt){
        for(auto it : mpt) {if(mps[it.first] < it.second) return false;} 
        return true;
    }    
        int _find(int window_size, string &s, string &t){
        unordered_map<char,int> mps, mpt;
        for(int i = 0; i < t.size(); ++i){mpt[t[i]]++;}
        int i = 0, j = 0;
        for(; j<min(window_size,(int)s.size()); ++j){mps[s[j]]++;}
        if(cmp(mps,mpt))return i;
        while(j < s.size()){
            mps[s[i]]--;
            mps[s[j]]++;
            if(cmp(mps,mpt))return i+1;
            i++; j++;
        }
        return -1;
    }

    int BS(string &s, string &t){
        int lo = 0, hi = 1e5, mid = -1, ans = -1;
        while(lo <= hi){
            mid = (lo+hi)>>1;
            if(_find(mid,s,t) != -1) {ans = mid; hi = mid-1;}
            else {lo = mid+1;}
        }
        return ans;
    }


    string minWindow(string s, string t) {
        int w = BS(s,t);
        return (w == -1)? "" : s.substr(_find(w,s,t),w);
    }
};
