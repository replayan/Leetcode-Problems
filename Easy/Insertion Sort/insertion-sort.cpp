//{ Driver Code Starts
// C program for insertion sort
#include <stdio.h>
#include <math.h>

/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}


// } Driver Code Ends

class Solution {
public:
    // Function to insert the element arr[i] into its correct position in the sorted array.
    void insert(int arr[], int i) {
        int key = arr[i];
        int j = i - 1;

        // Move elements greater than the key to the right.
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }

        // Insert the key at its correct position.
        arr[j + 1] = key;
    }

    // Function to sort the array using insertion sort algorithm.
    void insertionSort(int arr[], int n) {
        // Iterate through the array from the second element.
        for (int i = 1; i < n; i++) {
            // Insert the current element into the correct position in the sorted part of the array.
            insert(arr, i);
        }
    }
};


//{ Driver Code Starts.
int main()
{
    int arr[1000],n,T,i;

    scanf("%d",&T);

    while(T--){

    scanf("%d",&n);

    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);

    Solution ob;
    ob.insertionSort(arr, n);
    printArray(arr, n);
    }
    return 0;
}

// } Driver Code Ends