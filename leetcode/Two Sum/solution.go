func twoSum(nums []int, target int) []int {
    size := len(nums)
    for i := 0; i < size; i++ {
        for j := i + 1; j < size; j++ {
            if nums[i] + nums[j] == target {
                return []int{i + 1, j + 1}
            }
        }
    }
    return []int{0, 0}
}