class Solution {
public:
	// my solution runs for 12ms
	// add the following two lines at the beginning, it will run for 8ms
	// if(NULL == l1) return l2;
	// if(NULL == l2) return l1;
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *head = new ListNode(0);
        ListNode *ptr = head;
        while (l1 != NULL && l2 != NULL){
            if (l1->val < l2->val){
                ptr->next = l1;
                l1 = l1->next;
            }else{
                ptr->next = l2;
                l2 = l2->next;
            }
            ptr = ptr->next;
            ptr->next == NULL;
        }
        if (l1 == NULL) ptr->next = l2;
        else ptr->next = l1;
        return head->next;
    }
};