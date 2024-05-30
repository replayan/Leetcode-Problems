class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int n = size(arr), count = 0;
        vector<int> prefixXor(n + 1, 0);
        
        // the prefix XOR
        for (int i = 0; i < n; ++i) {
            prefixXor[i + 1] = prefixXor[i] ^ arr[i];
        }
        // Iterate over all pairs (i, k)
        for (int i = 0; i < n; ++i) {
            for (int k = i + 1; k < n; ++k) {
                // If prefixXor[i] == prefixXor[k + 1], it means XOR(i to k) is 0
                if (prefixXor[i] == prefixXor[k + 1]) {
                    // All j between i+1 and k are valid
                    count += (k - i);
                }
            }
        }
        return count;
    }
};
