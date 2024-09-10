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

int gcd(int a, int b){return b? gcd(b, a%b) : a;}

class Solution {
public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* cur = head;
        while(cur->next != NULL){
            ListNode* tmp = cur->next;
            cur->next = new ListNode (gcd(cur->val, tmp->val));
            cur->next->next = tmp;
            cur = tmp;
        }
        return head;
    }
};
