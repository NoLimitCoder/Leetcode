class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int n = people.size();
        int i = 0, j = n-1;
        int ans = 0;
        while(i<=j){
            int sum = people[j];
            //cout << "boat: ";
            if(sum < limit && i<j){
                sum += people[i++];
                if(sum > limit) {i--;}
                //cout << people[i] << ", ";
            }
            ans++;
            //cout << people[j] << " #" << ans << "\n";
            j--;
            
            
        }
        return ans;
    }
};
