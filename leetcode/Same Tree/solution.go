func dfs(p *TreeNode, q *TreeNode) bool {
	if p == nil && q == nil {
		return true
	}
	if (p == nil && q != nil ) || (p != nil && q == nil) {
		return false
	}
	if p.Val != q.Val {
		return false
	}
	if !dfs(p.Left, q.Left) {
		return false
	}
	if !dfs(p.Right, q.Right) {
		return false
	}
	return true
}

func isSameTree(p *TreeNode, q *TreeNode) bool {
	return dfs(p, q)
}
