class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size() % groupSize != 0) return false;
        map<int,int> mp;
        for(int a : hand){
            mp[a]++;
        }
        sort(hand.begin(), hand.end());
        for(int i = 0; i<hand.size(); ++i){
            //since each repeated card means start of a sequence, a card with frequency 0
            // at this step means that this card has already been taken for a sequence
            if(mp[hand[i]] == 0) continue;
            for(int j = 0; j<groupSize; ++j){
                if(mp[hand[i] + j] != 0){
                    mp[hand[i] + j]--;
                }
                else{
                    return false;
                }
            }
        }
        return true;
    }
    
};
