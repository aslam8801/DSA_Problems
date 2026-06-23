class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {

        if(head == nullptr || head->next == nullptr){
            return head;
        }

        ListNode* odd = head;
        ListNode* evenHead = head->next;
        ListNode* even = head->next;

        while(even && even->next){
            odd->next = odd->next->next;
            even->next = even->next->next;

            odd = odd->next;
            even = even->next;
        }

        odd->next = evenHead;

        return head;
    }
};