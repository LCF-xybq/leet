class Trie {
private:
  Trie *children[27];
  bool endOfWord = false;
public:
  /** Initialize data structure. */
  Trie() {
    endOfWord = false;
    for (int i = 0; i < 27; i++) {
      children[i] = nullptr;
    }
  }

  void insert(string word) {
    if (word.size() <= 0) return;
    Trie *root = this;
    for (auto v : word) {
      if (root->children[v - 'a'] == nullptr) {
        root->children[v - 'a'] = new Trie();
      }
      root = root->children[v - 'a'];
    }
    root->endOfWord = true;
  }

  bool search(string word) {
    if (word.size() <= 0) return false;
    Trie *root = this;
    for (auto v : word) {
      if (root->children[v - 'a'] == nullptr) return false;
      root = root->children[v - 'a'];
    }
    return root->endOfWord;
  }

  bool startsWith(string prefix) {
    if (prefix.size() <= 0) return false;
    Trie *root = this;
    for (auto v : prefix) {
      if (root->children[v - 'a'] == nullptr) return false;
      root = root->children[v - 'a'];
    }
    return true;
  }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
