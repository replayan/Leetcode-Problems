class CustomStack {
    vector<int> v;
    const int m;

public:
    CustomStack(int maxSize) : m(maxSize) {}

    void push(int x) {
        if (v.size() < m) {
            v.push_back(x);
        }
    }

    int pop() {
        if (v.empty()) {
            return -1;
        }
        const int r = v.back();
        v.pop_back();
        return r;
    }

    void increment(int k, int val) {
        for (int i = 0; i < k && i < v.size(); ++i) {
            v[i] += val;
        }
    }
};
