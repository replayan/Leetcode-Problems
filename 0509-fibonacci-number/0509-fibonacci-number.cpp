class Solution {
public:
    int fib(int n) {
        if (n < 2)
            return n;
        
        int prev = 0;
        int curr = 1;
        
        for (int i = 2; i <= n; i++) {
            int temp = curr;
            curr = prev + curr;
            prev = temp;
        }
        
        return curr;
    }
};