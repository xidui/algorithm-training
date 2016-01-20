// 20ms
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (head == NULL
            || head->next == NULL
            || head->next->next == NULL) return head;
        ListNode *odd_head = new ListNode(0),
                 *eve_head = new ListNode(0);
        ListNode *odd_cur = odd_head, *eve_cur = eve_head;
        bool odd = true;
        while (head != NULL){
            if (odd){
                odd_cur->next = head;
                odd_cur = odd_cur->next;
            } else {
                eve_cur->next = head;
                eve_cur = eve_cur->next;
            }
            odd = !odd;
            head = head->next;
        }
        odd_cur->next = eve_head->next;
        eve_cur->next = NULL;
        return odd_head->next;
    }
};