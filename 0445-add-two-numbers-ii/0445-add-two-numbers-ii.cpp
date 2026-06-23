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
    ListNode* reverseLL(ListNode* head){
        if(head == nullptr){
            return head;
        }

        ListNode* curr = head;
        ListNode* prev = nullptr;

        while(curr){
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        return prev;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1 = reverseLL(l1);
        l2 = reverseLL(l2);

        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;

        int carry = 0;
        while(l1 && l2){
            int sum = l1->val + l2->val + carry;
            ListNode* newNode = new ListNode(sum%10);
            carry = sum/10;
            curr->next = newNode;
            curr = newNode;
            l1 = l1->next;
            l2 = l2->next;
        }

        while(l1){
            int sum = l1->val + carry;
            ListNode* newNode = new ListNode(sum%10);
            carry = sum/10;
            curr->next = newNode;
            curr = newNode;
            l1 = l1->next;
        }

        while(l2){
            int sum = l2->val + carry;
            ListNode* newNode = new ListNode(sum%10);
            carry = sum/10;
            curr->next = newNode;
            curr = newNode;
            l2 = l2->next;
        }

        if(carry){
            curr->next = new ListNode(carry);
        }

        ListNode* head = dummy->next;
        delete dummy;
        head = reverseLL(head);
        return head;
    }
};