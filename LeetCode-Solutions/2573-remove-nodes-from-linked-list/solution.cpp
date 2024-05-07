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
    ListNode* reverse(ListNode* head) {
        ListNode *tmp = NULL, *prev = NULL;
        while(head != NULL){
            tmp = head;
            head = head->next;
            tmp->next = prev;
            prev = tmp;
        }
        return prev;
    }

    ListNode* removeNodes(ListNode* head) {
        head = reverse(head); 
        ListNode *cur = head;
        while(cur != NULL){
            while(cur->next != NULL && cur->next->val < cur->val)
                {cur->next = cur->next->next;}
            cur = cur->next;
        }
        return reverse(head);
    }
        
};
