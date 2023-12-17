class FoodRatings {
    unordered_map<string, pair<int, string>> rating;
    unordered_map<string, set<pair<int, string>>> cuisine;
public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for (int i = 0; i < foods.size(); ++i) {
            rating[foods[i]] = {ratings[i], cuisines[i]};
            cuisine[cuisines[i]].insert({-ratings[i], foods[i]});
        }
    }
    void changeRating(string food, int newRating) {
        auto t = rating.find(food);
        cuisine[t->second.second].erase({-t->second.first, food});
        rating[food] = {newRating, t->second.second};
        cuisine[t->second.second].insert({-newRating, food});
    }
    
    string highestRated(string c) {
        return cuisine[c].begin()->second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */