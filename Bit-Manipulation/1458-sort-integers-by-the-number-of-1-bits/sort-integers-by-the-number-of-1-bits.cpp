class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        int n = arr.size();
        
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                if (countSetBits(arr[j]) > countSetBits(arr[j + 1]) || 
                    (countSetBits(arr[j]) == countSetBits(arr[j + 1]) && arr[j] > arr[j + 1])) {
                    swap(arr[j], arr[j + 1]);
                }
            }
        }
        return arr;
    }  
private:
    int countSetBits(int num) {
        int count = 0;
        while (num) {
            count += (num & 1); 
            num >>= 1;
        }
        return count;
    }
};
