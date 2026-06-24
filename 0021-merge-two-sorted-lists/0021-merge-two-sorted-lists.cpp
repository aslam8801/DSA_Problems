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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == nullptr){
            return list2;
        }
        if(list2 == nullptr){
            return list1;
        }

        ListNode *t1 = list1, *t2 = list2;
        ListNode* dummy = new ListNode(-1);
        ListNode* curr = dummy;
        while(t1 != nullptr && t2 != nullptr){
            if(t1->val <= t2->val){
                curr->next = t1;
                curr = t1;
                t1 = t1->next;
            }else{
                curr->next = t2;
                curr = t2;
                t2 = t2->next;
            }
        }

        while(t1 != nullptr){
            curr->next = t1;
            curr = t1;
            t1 = t1->next;
        }

        while(t2 != nullptr){
            curr->next = t2;
            curr = t2;
            t2 = t2->next;
        }

        curr->next = nullptr;
        return dummy->next;
    }
};