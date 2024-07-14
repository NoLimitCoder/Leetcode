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
class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        set<int> st;
        for(int i : nums) st.insert(i);
        vector<int> ans;
        ListNode* cur = head;
        while(cur != NULL){
            if(st.find(cur->val) != st.end());
            else ans.push_back(cur->val);
            cur = cur->next;
        }
        if(ans.size() == 0) return NULL;
        head = new ListNode(ans[0]);
        ListNode* current = head;
    for (int i = 1; i < ans.size(); ++i) {
        current->next = new ListNode(ans[i]);
        current = current->next;
    }
    return head;

    }
};
