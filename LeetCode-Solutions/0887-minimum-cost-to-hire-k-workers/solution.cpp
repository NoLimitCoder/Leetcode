class Solution {
public:

    /*bool can(vector<int>& ratio, int m){

    }*/

    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
       vector<pair<double,double>> ratio;
       int n = quality.size();
       for(int i = 0; i<n; ++i){
        ratio.push_back({wage[i]*1.0/quality[i]*1.0,quality[i]});
       }
       sort(ratio.begin(), ratio.end());
       double w = ratio[k-1].first;
        priority_queue<double> pq;
        double quality_points = 0;
        for(int i = 0; i<k; ++i){
            pq.push(ratio[i].second);
            quality_points += ratio[i].second;
        }
        double ans = quality_points * w;
        for(int i = k; i<n; ++i){
            w = ratio[i].first;
            quality_points -= pq.top(); pq.pop();
            pq.push(ratio[i].second);
            quality_points += ratio[i].second;
            ans = min(ans, quality_points * w);
        }
    return ans;
    }
};
