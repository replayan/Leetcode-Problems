#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
class Solution {
public:
    // Global variables used in DP and automaton:
    string pat;         // pattern string s.
    int L;              // Length of s.
    int digitLimit;     // limit value.
    // Automaton: next[state][d] gives the next state when digit d is added.
    // Allowed digits are 0 ... digitLimit (as integers).
    int nextState[20][10]; // 20 is safe since L <= floor(log10(finish)) + 1 <= 16.
 
    // Build the automaton transitions: for state i in [0, L] and digit d in [0,digitLimit].
    // The state represents that the last i digits of the number equal the prefix s[0..i-1].
    void buildAutomaton() {
        // For each state from 0 to L, simulate appending a digit d.
        for (int state = 0; state <= L; state++) {
            for (int d = 0; d <= digitLimit; d++) {
                // We want to compute the maximum k (0 <= k <= L) such that the last k digits 
                // of (the sequence that yielded state) followed by digit d equals s[0..k-1].
                // If we had matched state digits (i.e. s[0..state-1]) and now add char c:
                char c = char('0' + d);
                string cur;
                if(state > 0) {
                    // We assume we have already matched pat[0..state-1].
                    cur = pat.substr(0, state);
                }
                cur.push_back(c);
                // Now, find the maximum k s.t. cur's suffix of length k equals pat[0..k-1].
                int best = 0;
                // k cannot exceed L or cur.size():
                int maxk = min((int)cur.size(), L);
                for (int k = 1; k <= maxk; k++) {
                    if (cur.substr(cur.size()-k, k) == pat.substr(0, k)) {
                        best = k;
                    }
                }
                nextState[state][d] = best;
            }
        }
    }
 
    // We now implement a standard digit DP that counts numbers <= num that satisfy:
    // 1) each digit is in [0, digitLimit] (when the number "starts")
    // 2) if the number has at least L digits then its final L digits equal pat.
    //
    // DP state parameters:
    // pos: current position (0-indexed from the most significant digit in "num")
    // tight: whether we are bound by the prefix of num (0/1)
    // started: whether we have started (i.e. chosen a nonzero digit) (0/1)
    // state: the current automaton state (i.e. how many last digits match pat).
    // len: the number of digits placed (once started).
    //
    // We only count a number as valid if at the end (pos==n) we have started and len >= L and state==L.
    string digits;
    ll dp[25][2][2][25]; // dimensions: pos up to 25 (safe for 1e15), tight=2, started=2, state up to 20.
    bool seen[25][2][2][25];
 
    // Recursive DP function.
    ll solve_dp(int pos, int tight, int started, int state, int len) {
        if (pos == digits.size()) {
            // Only count if we have built a positive integer with at least L digits and the automaton state is L.
            return (started && len >= L && state == L) ? 1LL : 0LL;
        }
        if (seen[pos][tight][started][state])
            return dp[pos][tight][started][state];
 
        seen[pos][tight][started][state] = true;
        ll res = 0;
 
        // Determine the upper bound for the current digit.
        int ub = tight ? (digits[pos]-'0') : digitLimit;
        // But if ub is greater than digitLimit, we cannot use digits > digitLimit because of our constraint.
        ub = min(ub, digitLimit);
 
        for (int d = 0; d <= ub; d++) {
            int ntight = tight;
            if (tight && d < (digits[pos]-'0'))
                ntight = 0;
 
            int nstarted = started;
            int nlen = len;
            int nstate = state;
            if (!started && d == 0) {
                // still not started, state remains 0.
            } else {
                if (!started) {
                    nstarted = 1;
                    nlen = 0;
                    nstate = 0; // starting afresh.
                }
                nlen++;
                // Update the automaton state with the new digit.
                nstate = nextState[nstate][d];
            }
 
            res += solve_dp(pos+1, ntight, nstarted, nstate, nlen);
        }
 
        dp[pos][tight][started][state] = res;
        return res;
    }
 
    // Helper function: count valid numbers <= X.
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
 
        ll ans = countNumbers(finish) - countNumbers(start - 1);
        return ans;
    }
};
 
// Example usage and testing:
#ifdef DEBUG
int main() {
    Solution sol;
    // Test with a simple example.
    // For instance: start = 1, finish = 1000, limit = 5, s = "25"
    long long start = 1, finish = 1000;
    int limit = 5;
    string s = "25";
    cout << sol.numberOfPowerfulInt(start, finish, limit, s) << endl;
    return 0;
}
#endif
