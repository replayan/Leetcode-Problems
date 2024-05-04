class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(begin(people), end(people));
        int i = 0, j = people.size() - 1, noOfBoats = 0;
        while (i <= j) {
            if (people[i] + people[j] <= limit) {
                ++i;
            }
            --j;
            noOfBoats += 1;
        }
        return noOfBoats;
    }
};