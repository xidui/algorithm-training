public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
    ListNode head  = new ListNode(0);
    ListNode cur = head;
    int carry = 0;
        
    while (l1 != null || l2 != null || carry != 0) {
        int sum = 0, rem = 0;
        if (l1 != null) {
            sum += l1.val;
            l1 = l1.next;
        }
            
        if (l2 != null) {
            sum += l2.val;
            l2 = l2.next;
        }
           
        rem = (carry +sum) % 10;
        carry = (carry + sum) / 10;
        cur.next = new ListNode(rem);
        cur = cur.next;
    }
            
    return head.next;
}