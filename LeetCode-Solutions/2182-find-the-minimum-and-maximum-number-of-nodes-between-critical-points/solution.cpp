/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
 #pragma GCC optimize("O3,unroll-loops")
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ListNode *prev = head, *cur = head->next;
        int i = 1, first = -1, current = 0, mn = 1e5;
        while(cur->next != NULL){
            if(  (cur->val < prev->val && cur->val < cur->next->val) || (cur->val > prev->val && cur->val > cur->next->val) ){
                if(first != -1){ mn = min(mn,i+1 - current); current = i+1; }
                else{ first = current = i+1; }
            }
            prev = cur; cur = cur->next; ++i;
        }
        if(mn == 1e5) return {-1,-1};
        return {mn,current-first};
    }
};

auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();
