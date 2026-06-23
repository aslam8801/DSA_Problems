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
    void deleteNode(ListNode* node) {
        ListNode* nextNode = node->next;
        node->val = nextNode->val;

        if(nextNode->next == NULL){
            node->next = NULL;
            delete nextNode;
            return ;
        }
        node->next = nextNode->next;
        nextNode->next = NULL;
        delete nextNode;
        return ;
    }
};