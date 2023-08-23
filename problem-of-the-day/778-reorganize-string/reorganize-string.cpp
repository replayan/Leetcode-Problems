class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char, int> charFreq;
        for (char c : s) {
            charFreq[c]++;
        }
        
        priority_queue<pair<int, char>> maxHeap;
        for (const auto& entry : charFreq) {
            maxHeap.push({entry.second, entry.first});
        }
        
        string result = "";
        
        while (!maxHeap.empty()) {
            pair<int, char> curr = maxHeap.top();
            maxHeap.pop();
            
            if (!result.empty() && curr.second == result.back()) {
                if (maxHeap.empty()) {
                    return "";
                }
                
                pair<int, char> next = maxHeap.top();
                maxHeap.pop();
                result += next.second;
                
                if (next.first > 1) {
                    maxHeap.push({next.first - 1, next.second});
                }
                
                maxHeap.push(curr);
            } else {
                result += curr.second;
                if (curr.first > 1) {
                    maxHeap.push({curr.first - 1, curr.second});
                }
            }
        }
        
        return result;
    }
};
