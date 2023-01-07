#define deb(x) cerr << #x <> ": " << x << '\n'

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = (int)gas.size();
        //brute force:
        /*
        for(int Starting_idx = 0; Starting_idx < n; ++Starting_idx){
            int tank = 0;
            for(int i = 0; i < n; ++i){
                tank +=  gas[(Starting_idx  + i)%n];
                tank -= cost[(Starting_idx  + i)%n];
                if(tank < 0) break;
                if(i == n-1){return Starting_idx;}
            }
        }*/

        //greedy:
            int i = 0, j = n;
            int tank = 0;
            while(j > i){
                if(tank >= 0){
                    tank += gas[i];
                    tank -= cost[i];
                    ++i;
                }
                else{
                    --j;
                    tank +=  gas[j];
                    tank -= cost[j];
                }
            }
        if(tank >= 0){return j%n;}
        return -1;
    }
};
