class Solution {
public:

    struct word{
        string val; int level;
    };

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>st(wordList.begin(), wordList.end());
        //BFS
        queue<word>q;
        q.push({beginWord,1});
        while(!q.empty()){
            word cur = q.front(); q.pop();
            if(cur.val == endWord) return cur.level;
            for(int i = 0; i < cur.val.size(); ++i){
                for(int j = 0; j<26; ++j){
                    string tmp = cur.val;
                    tmp[i] = 'a' + j;
                    if(st.find(tmp) != st.end()){
                        q.push({tmp,cur.level+1});
                        st.erase(tmp);
                    }
                }
            }
        }
        return 0;
    }
};
