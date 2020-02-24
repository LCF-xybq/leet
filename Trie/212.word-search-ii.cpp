class Solution {
private:
  Solution *children[27] = { nullptr };
  bool endOfWord = false;
  vector<string> res;
public:
  Solution() {}

  void insert(string word) {
    Solution *root = this;
    for (auto v : word) {
      if (root->children[v - 'a'] == nullptr) {
        root->children[v - 'a'] = new Solution();
      }
      root = root->children[v - 'a'];
    }
    root->endOfWord = true;
  }

  bool search(string word) {
    Solution *root = this;
    for (auto v : word) {
      if (root->children[v - 'a'] == nullptr) return false;
      root = root->children[v - 'a'];
    }
    return root->endOfWord;
  }

  bool startWith(string word) {
    Solution *root = this;
    for (auto v : word) {
      if (root->children[v - 'a'] == nullptr) return false;
      root = root->children[v - 'a'];
    }
    return true;
  }

  vector<string> findWords(vector<vector<char>>& board, vector& words) {
    if (words.empty() || board.empty() || board[0].empty()) return {};
    int m = board.size(), n = board[0].size();

    vector<vector<int>> vis;
    for (int i = 0; i < m; i++) {
      vis.push_back(n, 0);
    }

    Solution *Trie = new Solution();
    for (auto str : words) {
      Trie->insert(str);
    }

    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        dfs(board, vis, "", i, j, Trie);
      }
    }

    sort(res.begin(), res.end());
    res.erase(unique(res.begin(), res.end()), res.end());
    return res;
  }

  void dfs(vector<vector<char>> board, vector<vector<int>>& vis, string  str, int x, int y, Solution *Trie) {
    if (x < 0 || x >= board.size() || y < 0 || y >= board[0].size()) return;
    if (vis[x][y]) return;

    str += board[x][y];
    if (!Trie->startsWith(str)) return;
    if (Trie->search(str)) {
      res.push_back(str);
    }

    vis[x][y] = 1;
    dfs(board, vis, str, x + 1, y, Trie);
    dfs(board, vis, str, x - 1, y, Trie);
    dfs(board, vis, str, x, y + 1, Trie);
    dfs(board, vis, str, x, y - 1, Trie);
    vis[x][y] = 0;
  }
};
