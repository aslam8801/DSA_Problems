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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == nullptr || head->next == nullptr){
            return head;
        }
        int len = 0;
        ListNode* temp = head;
        while(temp != nullptr){
            len += 1;
            temp = temp->next;
        }

        k %= len;
        if(k == 0){
            return head;
        }

        int tar = len - k;
        temp = head;
        while(temp != nullptr){
            tar--;
            if(tar == 0){
                break;
            }
            temp = temp->next;
        }
        ListNode* newHead = temp->next;
        temp->next = nullptr;
        ListNode* last = newHead;
        while(last->next != nullptr){
            last = last->next;
        }
        last->next = head;
        return newHead;
    }
};