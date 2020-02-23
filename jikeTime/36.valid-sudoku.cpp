class Solution {
public:
  bool isValidSudoku(vector<vector<char>>& board) {
    if (board.empty() || board[0].empty()) return false;
      return solve(board);
    }

  bool solve(vector<vector<char>> board) {
    for (int i = 0; i < board.size(); i++) {
      for (int j = 0; j < board[0].size(); j++) {
        if (board[i][j] != '.') {
          if (!isValid(board, i, j, board[i][j])) return false;
        }
      }
    }
    return true;
  }

  bool isValid(vector<vector<char>> board, int row, int col, char c) {
    for (int i = 0; i < 9; i++) {
      if (i != row && board[i][col] != '.' && board[i][col] == c) return false;
        if (i != col && board[row][i] != '.' && board[row][i] == c) return false;
          int m = 3 * (row / 3) + i /3, n = 3 * (col / 3) + i % 3;
          if (m != row && n != col && board[m][n] != '.' && board[m][n] == c) return false;
    }
    return true;
  }
};
