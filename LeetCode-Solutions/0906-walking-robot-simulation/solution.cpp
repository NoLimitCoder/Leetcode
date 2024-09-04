#define rep(i,n) for(int i = 0; i<n; ++i)
auto init = []() { ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); return 0; }();
char turn_left(char dir){
        if(dir == 'u') return 'l';
        if(dir == 'l') return 'd';
        if(dir == 'd') return 'r';
        if(dir == 'r') return 'u';
        return dir;
    }

    char turn_right(char dir){
        if(dir == 'u') return 'r';
        if(dir == 'r') return 'd';
        if(dir == 'd') return 'l';
        if(dir == 'l') return 'u';
        return dir;
    }


class Solution {
public:


    static int robotSim(vector<int>& C, vector<vector<int>>& obstacles) {
        set<pair<int,int>> st;
        rep(i,obstacles.size()){
            st.insert({obstacles[i][0],obstacles[i][1]});
        }
        pair<int,int> cur = {0,0};
        char dir = 'u';
        int mx = 0;
        //debl(dir); debl(cur.first); deb(cur.second);
        rep(i,C.size()){
            if(C[i] == -1){
                //deb("right");
                char tmp = turn_right(dir);
                dir = tmp;
            }
            else if(C[i] == -2){
                //deb("left");
                char tmp = turn_left(dir);
                dir = tmp;
            }
            
            else{
                if(dir == 'u'){
                    rep(k,C[i]){
                        cur.second++;
                        if(st.find(cur) != st.end()){cur.second--; break;}
                    }
                }
                if(dir == 'd'){
                    rep(k,C[i]){
                        cur.second--;
                        if(st.find(cur) != st.end()){cur.second++; break;}
                    }
                }
                if(dir == 'r'){
                    rep(k,C[i]){
                        cur.first++;
                        if(st.find(cur) != st.end()){cur.first--; break;}
                    }
                }
                if(dir == 'l'){
                    rep(k,C[i]){
                        cur.first--;
                        if(st.find(cur) != st.end()){cur.first++; break;}
                    } 
                }
                //debl(dir); debl(cur.first); deb(cur.second);
            }
            
            mx = max(mx, cur.first*cur.first + cur.second*cur.second);
        }
        return mx;
    }
};
