class Solution {
public:
    int passThePillow(int n, int time) {
        int direction = 1; // 1 means moving right, -1 means moving left
        int index = 0; // starting at the first person (index 0)
        
        for (int t = 0; t < time; ++t) {
            index += direction;
            if (index == n - 1 || index == 0) {
                direction *= -1; // reverse the direction
            }
        }
        
        return index + 1; // converting 0-based index to 1-based index
    }
};
