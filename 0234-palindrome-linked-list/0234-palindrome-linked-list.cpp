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
    bool isPalindrome(ListNode* head) {
        if(head == nullptr || head->next == nullptr){
            return true;
        }

        stack<int> st;
        ListNode* curr = head;
        while(curr){
            st.push(curr->val);
            curr = curr->next;
        }

        curr = head;
        while(curr){
            if(curr->val != st.top()){
                return false;
            }
            st.pop();
            curr = curr->next;
        }

        return true;
    }
};