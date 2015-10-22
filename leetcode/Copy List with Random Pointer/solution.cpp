// using hash table may be faster
// this solution is 128ms
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if (NULL == head) return NULL;
        RandomListNode *ptr1, *ptr2, *head2;
        head2 = new RandomListNode(head->label);
        ptr1 = head; ptr2 = head2;
        map<RandomListNode*, RandomListNode*> mrr;
        while (NULL != ptr1){
            mrr[ptr1] = ptr2;
            if (ptr1->next != NULL){
                   ptr2->next = new RandomListNode(ptr1->next->label);
            }
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }

        ptr1 = head; ptr2 = head2;
        while (NULL != ptr1){
            if (NULL != ptr1->random)
                ptr2->random = mrr[ptr1->random];
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }

        return head2;
    }
};