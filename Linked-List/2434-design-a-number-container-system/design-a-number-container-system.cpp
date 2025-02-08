class NumberContainers {
    unordered_map<int, int> index2num;
    unordered_map<int, set<int>> num2index;

public:
    NumberContainers() {}

    void change(int index, int number) {
        auto t = index2num.find(index);
        if (t != index2num.end()) {
            num2index[t->second].erase(index);
        }
        index2num[index] = number;
        num2index[number].insert(index);
    }

    int find(int number) {
        auto t = num2index.find(number);
        if (t == num2index.end() || t->second.empty()) {
            return -1;
        }
        return *t->second.begin();
    }
};