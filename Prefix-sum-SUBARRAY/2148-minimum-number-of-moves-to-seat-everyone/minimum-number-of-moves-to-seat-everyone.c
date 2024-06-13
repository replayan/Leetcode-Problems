int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int minMovesToSeat(int* seats, int seatsSize, int* students, int studentsSize) {
    // Sort the seats and students arrays
    qsort(seats, seatsSize, sizeof(int), compare);
    qsort(students, studentsSize, sizeof(int), compare);

    int moves = 0;
    for (int i = 0; i < seatsSize; ++i) {
        moves += abs(seats[i] - students[i]);
    }
    
    return moves;
}