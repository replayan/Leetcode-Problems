class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        sort(deck.begin(), deck.end());
        const int n = deck.size();
        queue<int> q;
        for (int i = 0; i < n; ++i) {
            q.push(i);
        }
        vector<int> r(n);
        for (int i = 0, j = 0; i < n; j ^= 1) {
            if (j) {
                q.push(q.front());
           } else {
            r[q.front()] = deck[i++];
           }
           q.pop();
        }
        return r;
    }
};