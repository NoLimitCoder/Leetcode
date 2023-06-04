class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int>> cars;
        for(int i = 0; i<position.size(); ++i){
            cars.push_back({position[i],speed[i]});
        }
        sort(cars.begin(),cars.end());
        stack<double> fleets;
        //time = d/v = (target - position) / (speed)
        double d = target - cars[cars.size()-1].first, v = cars[cars.size()-1].second;
        fleets.push(d/v);
        for(int i = cars.size()-2; i >=0; --i){
            d = target - cars[i].first, v = cars[i].second;
            if(d/v <= fleets.top()) continue;
            else{fleets.push(d/v);}
        }
        return fleets.size();
    }
};
