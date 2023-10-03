int numIdenticalPairs(int* nums, int numsSize) {
    int arr[101]={0}, gp=0;  
    for (int i=0; i<numsSize; ++i) {
        int n = nums[i]; 
        arr[n]++; 
        gp += arr[n]-1;
    }
    return gp;
}
