/* stuff you should look for 
    * check for int overflow
    * check for time complexity (make sure not to TLE)
    * special case (n = 1)
    * make sure to initialize everything (array)
    * don't be lazy, write out your thought and code it out
*/
const int ALPHABET = 26;

struct Node {
    struct Node* next[ALPHABET];
    bool isEnd = false;
};

template <const char MIN_CHAR = 'a'>
struct Trie {
private:
    Node* node;

public:
    Trie() {
        node = new Node();
    }

    Node* GetNode() {
        return node;
    }

    void insert(string word) {
        Node* cur = node;
        for (char c : word) {
            if (cur -> next[c - MIN_CHAR] == NULL) {
                cur -> next[c - MIN_CHAR] = new Node();
            }
            cur = cur -> next[c - MIN_CHAR];
        }
        cur -> isEnd = true;
    }

    bool find(string word, bool isPrefix = false) {
        Node* cur = node;
        for (char c : word) {
            if (cur -> next[c - MIN_CHAR] == NULL) {
                return false;
            }
            cur = cur -> next[c - MIN_CHAR];
        }
        return (isPrefix ? true : cur -> isEnd);
    }
};

const int N = 15;
const int D = 4;
const int di[D] = {-1, 0, 1, 0};
const int dj[D] = {0, -1, 0, 1};
const char used = '#';

class Solution {
private:
    int n, m;
    vector<vector<char>> board;
    unordered_set<string> bucket;

    bool in_bound(int i, int j) {
        return 0 <= i && i < n && 0 <= j && j < m && board[i][j] != used;
    }

    void dfs(int i, int j, Node* node, string word) {
        char cur = board[i][j];

        node = node->next[cur - 'a'];

        if (node == nullptr)
            return;

        word += cur;

        if (node->isEnd)
            bucket.insert(word);

        board[i][j] = '#';

        for (int d = 0; d < D; d++) {
            int ni = i + di[d];
            int nj = j + dj[d];
            if (in_bound(ni, nj)) {
                dfs(ni, nj, node, word);
            }
        }

        board[i][j] = cur;
    }

public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        this->board = board;
        n = board.size(), m = board[0].size();

        Trie tr;
        
        for (auto& word : words) tr.insert(word);

        auto node = tr.GetNode();

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                dfs(i, j, node, "");

        vector<string> ans(bucket.begin(), bucket.end());

        return ans;
    }
};