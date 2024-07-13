class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();
        vector<int> result;
        
        // Create a vector of tuples to hold the combined data along with original indices
        vector<tuple<int, int, char, int>> robots;
        for (int i = 0; i < n; ++i) {
            robots.emplace_back(positions[i], healths[i], directions[i], i);
        }

        // Sort robots by positions
        sort(robots.begin(), robots.end());

        // Use a stack to handle the collisions
        stack<tuple<int, int, char, int>> st;

        for (auto& robot : robots) {
            int pos = get<0>(robot);
            int health = get<1>(robot);
            char direction = get<2>(robot);
            int idx = get<3>(robot);

            if (direction == 'R') {
                st.push(robot);
            } else { // direction == 'L'
                while (!st.empty() && get<2>(st.top()) == 'R') {
                    auto [r_pos, r_health, r_direction, r_idx] = st.top();
                    st.pop();

                    if (r_health > health) {
                        st.push({r_pos, r_health - 1, r_direction, r_idx});
                        health = 0;
                        break;
                    } else if (r_health < health) {
                        health -= 1;
                    } else {
                        health = 0;
                        break;
                    }
                }
                if (health > 0) {
                    st.push({pos, health, direction, idx});
                }
            }
        }

        // Collect the healths of surviving robots in their original order
        vector<pair<int, int>> survivors;
        while (!st.empty()) {
            auto [pos, health, direction, idx] = st.top();
            st.pop();
            survivors.push_back({idx, health});
        }
        
        // Sort survivors by their original indices
        sort(survivors.begin(), survivors.end());

        for (auto& survivor : survivors) {
            result.push_back(survivor.second);
        }

        return result;
    }
};
