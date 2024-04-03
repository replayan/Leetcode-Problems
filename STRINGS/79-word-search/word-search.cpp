class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
    bool isEndOfWord;

    TrieNode() {
        isEndOfWord = false;
    }
};

class Trie {
public:
    TrieNode* root;

    Trie() {
        root = new TrieNode();
    }

    void insert(string word) {
        TrieNode* node = root;
        for (char c : word) {
            if (!node->children.count(c)) {
                node->children[c] = new TrieNode();
            }
            node = node->children[c];
        }
        node->isEndOfWord = true;
    }
};

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        Trie trie;
        trie.insert(word);

        int m = board.size();
        int n = board[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (dfs(board, trie.root, i, j)) {
                    return true;
                }
            }
        }

        return false;
    }

private:
    bool dfs(vector<vector<char>>& board, TrieNode* node, int i, int j) {
        if (node->isEndOfWord) {
            return true;
        }

        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size()) {
            return false;
        }

        char c = board[i][j];
        if (c == '#' || !node->children.count(c)) {
            return false;
        }

        board[i][j] = '#';

        bool found = dfs(board, node->children[c], i + 1, j) ||
                     dfs(board, node->children[c], i - 1, j) ||
                     dfs(board, node->children[c], i, j + 1) ||
                     dfs(board, node->children[c], i, j - 1);

        board[i][j] = c;

        return found;
    }
};