class Solution {
public:
    long long int maxKelements(vector<int>& nums, int k) {
        long long result = 0;
        priority_queue<int> max_heap(nums.begin(), nums.end());  

        while (k--) {
            int n = max_heap.top();
            max_heap.pop();
            result += n;
            max_heap.push(ceil(n / 3.0));  
        }
        return result;
    }
};