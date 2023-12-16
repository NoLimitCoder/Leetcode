#define deb(x) cout <<#x<<": "<<x<<'\n';
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        //convert Dict into set why? becuase we want to query in log(n) time
        set<string>st;
        for(string str : wordDict){
            st.insert(str);
            //deb(str);
        }
        string temp = " " + s;
        vector<int> indexes; //this will have the possible indexes for words
        int dp[305];
        memset(dp,0,sizeof(dp));
        indexes.push_back(0);
        dp[0] = 1;
        //" leetcode"
        for(int i = 1; i<temp.size(); ++i){
            //check all previous 1s in dp table == check elements on Array indexes
            for(int idx : indexes){
                //[0 - 5]
                //[starting, length]
                //if(idx > i) break;
                string str = temp.substr(idx+1, i-idx);
                //deb(str);
                //deb(idx);
                if(st.find(str) != st.end()){
                    //deb(dp[i]);
                    indexes.push_back(i); // dp[i] = 1
                    dp[i] = 1;
                   break;
                }
            }

        }
        int n = s.size();
        return dp[n] == 1;
    }
};

