class Solution {
    int get(char c) {
        switch (c) {
        case 'a':
            return 0;
        case 'e':
            return 1;
        case 'i':
            return 2;
        case 'o':
            return 3;
        case 'u':
            return 4;
        default:
            return 5;
        }
    }

public:
    long long countOfSubstrings(string word, int k) {
        const int n = word.length();
        vector<vector<int>> have(n + 1, vector<int>(6, n));
        for (int i = n - 1; i >= 0; --i) {
            have[i] = have[i + 1];
            have[i][get(word[i])] = i;
        }
        long long r = 0;
        vector<int> c(6);
        for (int i = 0, j = 0; i < n; ++i) {
            for (j = max(i, j); j < n && c[5] < k; ++j) {
                ++c[get(word[j])];
            }
            if (c[5] < k)
                break;
            // [i, j) contains excatly k consonants.
            bool ok = true;
            int e = j;
            for (int x = 0; ok && x < 5; ++x) {
                if (c[x] == 0) {
                    if (have[j][x] >= n) {
                        ok = false;
                    } else {
                        e = max(e, have[j][x] + 1);
                    }
                }
            }
            if (ok && e <= have[j][5]) {
                r += have[j][5] - e + 1;
            }
            if (i < j) {
                --c[get(word[i])];
            }
        }
        return r;
    }
};