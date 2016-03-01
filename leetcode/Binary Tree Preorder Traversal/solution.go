func preorderTraversal(root *TreeNode) []int {
    ans := []int{}
    set := []*TreeNode{}

    ptr := root
    deal := func (p *TreeNode) {
        for p != nil {
            set = append(set, p)
            ans = append(ans, p.Val)
            p = p.Left
        }
    }
    deal(ptr)

    for len(set) != 0 {
        ptr = set[len(set) - 1].Right
        set = append(set[:len(set) - 1], set[len(set):]...)
        if ptr == nil {
            continue
        }
        deal(ptr)
    }

    return ans
}
