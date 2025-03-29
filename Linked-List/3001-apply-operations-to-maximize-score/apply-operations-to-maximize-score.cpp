class Solution {
    const int M = 1000000007;
    long long cal(long long from, long long mid, long long to) {
        return (mid - from + 1) * (to - mid + 1);
    }
    
    int mul(long long x, long long y) {
        return x * y % M;
    }
    
    int pow(int x, int y) {
        int r = 1;
        for (; y; y >>= 1) {
            if (y & 1) {
                r = mul(r, x);
            }
            x = mul(x, x);
        }
        return r;
    }
    
    int cal(int x) {
        int r = 0;
        for (int i = 2; x / i >= i; ++i) {
            if (x % i == 0) {
                ++r;
                while (x % i == 0) {
                    x /= i;
                }
            }
        }
        if (x > 1) {
            ++r;
        }
        return r;
    }
public:
    int maximumScore(vector<int>& nums, long long k) {
        const int n = nums.size();
        stack<int> s;
        map<int, long long> have;
        vector<int> v(n);
        for (int i = 0; i < n; ++i) {
            v[i] = cal(nums[i]);
            while (!s.empty() && v[s.top()] < v[i]) {
                const int x = s.top();
                s.pop();
                have[nums[x]] += cal(s.empty() ? 0 : (s.top() + 1), x, i - 1);
            }
            s.push(i);
        }
        while (!s.empty()) {
            const int x = s.top();
            s.pop();
            have[nums[x]] += cal(s.empty() ? 0 : (s.top() + 1),  x, n - 1);
        }
        int r = 1;
        for (auto t = have.rbegin(); t != have.rend(); ++t) {
            const long long temp = min(k, t->second);
            r = mul(r, pow(t->first, temp));
        
            k -= temp;
            if (k == 0) {
                break;
            }
        }
        return r;
        
    }
};