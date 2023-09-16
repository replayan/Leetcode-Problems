class Solution {
public:
    int countPrimes(int n) {
        if (n <= 2) {
            return 0; // No prime numbers less than 2
        }

        // Create a boolean array to mark prime numbers
        vector<bool> isPrime(n, true);

        // 0 and 1 are not prime numbers
        isPrime[0] = isPrime[1] = false;

        // Start from 2, the first prime number
        for (int i = 2; i * i < n; ++i) {
            if (isPrime[i]) {
                // Mark all multiples of i as not prime
                for (int j = i * i; j < n; j += i) {
                    isPrime[j] = false;
                }
            }
        }

        // Count the prime numbers
        int count = 0;
        for (int i = 2; i < n; ++i) {
            if (isPrime[i]) {
                count++;
            }
        }

        return count;
    }
};
