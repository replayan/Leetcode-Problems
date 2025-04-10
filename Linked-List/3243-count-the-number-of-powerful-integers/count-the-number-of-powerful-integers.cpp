typedef long long ll;
class Solution {
public:
    string pat;
    int L, digitLimit;
    int nextState[20][10];
    string digits;
    ll dp[25][2][2][25];
    bool seen[25][2][2][25];

    void buildAutomaton() {
        for (int state = 0; state <= L; state++) {
            for (int d = 0; d <= digitLimit; d++) {
                char c = char('0' + d);
                string cur = (state > 0 ? pat.substr(0, state) : "") + c;
                int best = 0, maxk = min((int)cur.size(), L);
                for (int k = 1; k <= maxk; k++) {
                    if (cur.substr(cur.size() - k, k) == pat.substr(0, k)) best = k;
                }
                nextState[state][d] = best;
            }
        }
    }

    ll solve_dp(int pos, int tight, int started, int state, int len) {
        if (pos == digits.size())
            return (started && len >= L && state == L) ? 1LL : 0LL;
        if (seen[pos][tight][started][state])
            return dp[pos][tight][started][state];
        seen[pos][tight][started][state] = true;

        ll res = 0;
        int ub = tight ? (digits[pos] - '0') : digitLimit;
        ub = min(ub, digitLimit);

        for (int d = 0; d <= ub; d++) {
            int ntight = tight && d == (digits[pos] - '0');
            int nstarted = started, nlen = len, nstate = state;
            if (!started && d == 0) {
            } else {
                if (!started) {
                    nstarted = 1;
                    nlen = 0;
                    nstate = 0;
                }
                nlen++;
                nstate = nextState[nstate][d];
            }
            res += solve_dp(pos + 1, ntight, nstarted, nstate, nlen);
        }
        return dp[pos][tight][started][state] = res;
    }

    ll countNumbers(ll X) {
        if (X < 0) return 0LL;
        digits = to_string(X);
        memset(seen, 0, sizeof(seen));
        return solve_dp(0, 1, 0, 0, 0);
    }

    long long numberOfPowerfulInt(long long start, long long finish, int limit, string s) {
        digitLimit = limit;
        pat = s;
        L = s.size();
        buildAutomaton();
        return countNumbers(finish) - countNumbers(start - 1);
    }
};
