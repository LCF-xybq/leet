class Solution {
private:
  int count;
public:
  int totalNQueens(int n) {
    count  = 0;
    if (n <= 0) return 0;
    dfs(0, 0, 0, 0, n);
    return count;
  }

  void dfs(int row, int col, int pie, int na, int n) {
    if (row >= n) {
      count++;
      return;
    }
    int bits = (~(col | pie | na)) & ((1 << n) - 1);
    while (bits > 0) {
      int p = bits & -bits;
      dfs(row + 1, col | p, (pie | p) << 1, (na | p) >> 1, n);
      bits &= bits - 1;
    }
  }
};
