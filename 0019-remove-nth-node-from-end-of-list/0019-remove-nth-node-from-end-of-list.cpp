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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int cnt = 0;
        if(head == nullptr){
            return head;
        }

        ListNode* curr = head;

        while(curr){
            curr = curr->next;
            cnt+=1;
        }

        int tar = cnt - n;

        if(tar == 0){
            ListNode* temp = head;
            head = head->next;
            delete temp;
            return head;
        }
        curr = head;
        while(tar > 1){
            curr = curr->next;
            tar--;
        }

        ListNode* temp = curr->next;
        curr->next = temp->next;
        delete temp;
        return head;
        
    }
};