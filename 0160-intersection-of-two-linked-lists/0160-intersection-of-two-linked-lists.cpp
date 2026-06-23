/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == nullptr || headB == nullptr){
            return nullptr;
        }

        ListNode *l1 = headA;

        while(l1){
             ListNode *l2 = headB;
            while(l2){
                if(l2 == l1){
                    return l1;
                }
                l2 = l2->next;
            }
            l1 = l1->next;
        }

        return nullptr;
    }
};