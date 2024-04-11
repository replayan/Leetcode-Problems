class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        sort(deck.begin(), deck.end());
        int n = deck.size();
        vector<int> res(n);
        deque<int> q;
        
        // Initialize the deque with indices
        for (int i = 0; i < n; ++i) {
            q.push_back(i);
        }
        
        for (int card : deck) {
            // Get the index from the front of the deque
            int idx = q.front();
            q.pop_front();
            
            // Assign the card to the index
            res[idx] = card;
            
            // Move the last index to the front of the deque
            if (!q.empty()) {
                q.push_back(q.front());
                q.pop_front();
            }
        }
        
        return res;
    }
};