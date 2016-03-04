var ans []int

func inorderTraversal(root *TreeNode) []int {
	ans = []int{}
	helper(root)
	return ans
}

func helper(root *TreeNode) {
	if root == nil {
		return
	}
	helper(root.Left)
	ans = append(ans, root.Val)
	helper(root.Right)
}