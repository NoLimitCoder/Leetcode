class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        /*int ans = 0;
        while(tickets[k] != 0){
            for(int i = 0; i<tickets.size(); ++i){
                if(tickets[i] != 0){
                    tickets[i]--; ans++;
                }
                if(i == k && tickets[k] == 0) break;
            }
        }
        return ans;
        */
        int ans = 0;
        for(int i = 0; i<tickets.size(); ++i){
         if(tickets[i] < tickets[k]){
            //if(i==k)continue;
            ans += tickets[i];
         }   
         else{
            if(i<=k) ans += tickets[k];
            else ans += (tickets[k]-1); 
         }
        }
        return ans;
    }
    
};
