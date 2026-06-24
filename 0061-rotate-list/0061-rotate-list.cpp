class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {

        if(head == nullptr || head->next == nullptr){
            return head;
        }

        int len = 0;
        ListNode* temp = head;

        while(temp){
            len++;
            temp = temp->next;
        }

        k %= len;

        if(k == 0){
            return head;
        }

        int tar = len - k;

        temp = head;

        for(int i = 1; i < tar; i++){
            temp = temp->next;
        }

        ListNode* newHead = temp->next;
        temp->next = nullptr;

        ListNode* last = newHead;

        while(last->next){
            last = last->next;
        }

        last->next = head;

        return newHead;
    }
};