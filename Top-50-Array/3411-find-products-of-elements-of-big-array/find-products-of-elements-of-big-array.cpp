class Solution {
    pair<long long, long long> count(long long n) {
        long long answer = 0, sum = 0, before = n, after = 0;
        for (int i = 0; before; ++i) {
            const long long x = before & 1;
            before >>= 1;
            const long long temp = (before << i) + (x ? (after + 1) : 0);
            answer += temp;
            sum += temp * i;
            after |= x << i;
        }
        return {answer, sum};
    }
    
    long long get(long long x) {
        if (x == 0) return 0;
        long long left = 1, right = x;
        while (left <= right) {
            const long long mid = (left + right) >> 1;
            if (count(mid).first <= x) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        pair<long long, long long> r = count(left - 1);
        x -= r.first;
        for (int i = 0; x;  ++i) {
            if ((left >> i) & 1) {
                --x;
                r.second += i;
            }
        }
        return r.second;
    }
    
    int mul(long long x, long long y, int m) {
        return x * y % m;
    }
    
    int f(long long y, int m) {
        int r = 1 % m;
        for (int x = 2; r && y; y >>= 1) {
            if (y & 1) {
                r = mul(r, x, m);
            }
            x = mul(x, x, m);
        }
        return r;
    }
    
 
public:
    vector<int> findProductsOfElements(vector<vector<long long>>& queries) {
        vector<int> r;
        for (const auto& q : queries) {
            r.push_back(f(get(q[1] + 1) - get(q[0]), q[2]));
        }
        return r;
    }
};