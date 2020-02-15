class Solution {
public:
  bool searchMatrix(vector<vector<int>>& matrix, int target) {
    if (matrix.empty()) return false;
    if (matrix[0].empty()) return false;
    int m = matrix[0].size();
    int i = matrix.size() - 1, j = 0;
    while (i >= 0 && j < m) {
      if (matrix[i][j] == target) {
        return true;
      } else if (matrix[i][j] > target) {
        i--;
      } else {
        j++;
      }
    }
    return false;
  }
};
