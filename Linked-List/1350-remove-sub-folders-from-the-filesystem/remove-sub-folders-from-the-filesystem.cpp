struct Node {
    Node() {
        mark = false;
        for (int i = 0; i < 27; ++i) {
            next[i] = nullptr;
        }
    }
    Node* next[27];
    bool mark;
};

bool insert(const string& folder, const int now, Node* root) {
    if (now >= folder.length()) {
        root->mark = true;
        return false;
    }
    const int c = (folder[now] == '/') ? 26 : (folder[now] - 'a');
    if (root->next[c] == nullptr) {
        root->next[c] = new Node();
    }
    return insert(folder, now + 1, root->next[c]) || root->mark;
}

class Solution {

public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(), folder.end(),
             [](const string& a, const string& b) {
                 return a.length() < b.length();
             });
        Node* root = new Node();
        vector<string> r;
        for (string& f : folder) {
            f.push_back('/');
            if (!insert(f, 0, root)) {
                f.pop_back();
                r.push_back(f);
            }
        }
        return r;
    }
};