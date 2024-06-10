int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int heightChecker(int* heights, int heightsSize) {
    int* clonedHeights = (int*)malloc(heightsSize * sizeof(int));
    for (int i = 0; i < heightsSize; ++i) {
        clonedHeights[i] = heights[i];
    }

    qsort(clonedHeights, heightsSize, sizeof(int), compare);

    int count = 0;
    for (int i = 0; i < heightsSize; ++i) {
        if (heights[i] != clonedHeights[i]) {
            count++;
        }
    }
    free(clonedHeights);
    return count;
}
