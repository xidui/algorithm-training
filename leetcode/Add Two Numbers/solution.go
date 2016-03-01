func addTwoNumbers(l1 *ListNode, l2 *ListNode) *ListNode {
    if l1 == nil {
        return l2
    }
    if l2 == nil {
        return l1
    }

    var head = new(ListNode)
    var ptr = head
    var pro = 0

    for l1 != nil || l2 != nil || pro != 0 {
        ptr.Next = new(ListNode)
        l1_v, l2_v := 0, 0
        if l1 != nil { l1_v = l1.Val }
        if l2 != nil { l2_v = l2.Val }
        val := l1_v + l2_v + pro
        ptr.Next.Val = val % 10
        ptr = ptr.Next
        pro = val / 10
        if l1 != nil { l1 = l1.Next }
        if l2 != nil { l2 = l2.Next }
    }

    a := []int{123}
    fmt.Println(a[0])
    return head.Next
}
