class Solution {
public:
    struct cmp {
        bool operator()(const ListNode *a, const ListNode *b) {
            if (NULL == a) return false;
            if (NULL == b) return true;
            return  a->val > b->val;
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, cmp> pq;
        for (int i = 0; i < lists.size(); ++i){
            if (NULL != lists[i]) pq.push(lists[i]);
        }
        ListNode *ptr, *head = new ListNode(0);
        ptr = head;
        while (pq.size()){
            if (NULL == pq.top()){
                pq.pop();
                continue;
            }
            ptr->next = pq.top();
            pq.pop();
            if (ptr->next->next != NULL){
                pq.push(ptr->next->next);
            }
            ptr = ptr->next;
            ptr->next = NULL;
        }
        return head->next;
    }
};