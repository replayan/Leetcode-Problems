function heightChecker(heights: number[]): number {
    const clonedHeights = [...heights];

    clonedHeights.sort((a, b) => a - b);

    let count = 0;
    for (let i = 0; i < heights.length; ++i) {
        if (heights[i] !== clonedHeights[i]) {
            count++;
        }
    }
    return count;
}
