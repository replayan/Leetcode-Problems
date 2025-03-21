class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes,
                                  vector<vector<string>>& ingredients,
                                  vector<string>& supplies) {
        const int n = ingredients.size();
        vector<unordered_set<string>> all(n);
        unordered_map<string, vector<int>> need;
        for (int i = 0; i < n; ++i) {
            for (const auto& ingredient : ingredients[i]) {
                need[ingredient].push_back(i);
                all[i].insert(ingredient);
            }
        }
        unordered_set<int> have;
        queue<string> q;
        for (const auto& supply : supplies) {
            q.push(supply);
        }
        vector<string> r;
        while (!q.empty()) {
            const auto ingredient = q.front();
            q.pop();
            for (const int i : need[ingredient]) {
                if (have.find(i) != have.end()) {
                    continue;
                }
                all[i].erase(ingredient);
                if (all[i].empty()) {
                    have.insert(i);
                    q.push(recipes[i]);
                    r.push_back(recipes[i]);
                }
            }
        }
        return r;
    }
};