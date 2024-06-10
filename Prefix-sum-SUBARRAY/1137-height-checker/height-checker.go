func heightChecker(heights []int) int {
	clonedHeights := make([]int, len(heights))
	copy(clonedHeights, heights)

	sort.Ints(clonedHeights)

	count := 0
	for i := 0; i < len(heights); i++ {
		if heights[i] != clonedHeights[i] {
			count++
		}
	}
	return count
}
