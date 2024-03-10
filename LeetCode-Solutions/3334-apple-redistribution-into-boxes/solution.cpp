class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        sort(capacity.rbegin(),capacity.rend());
        int sum = 0;
        for(int i = 0; i<apple.size(); ++i){
            sum+= apple[i];
        }
        int i = 0;
        while(sum>0){
            sum -= capacity[i++];
        }
        return i;
    }
};
